#define BLYNK_TEMPLATE_ID "TMPL3cSOPj0Pq"
#define BLYNK_TEMPLATE_NAME "iot project"
#define BLYNK_AUTH_TOKEN "H5iLXkZm_Rv-aY0ntBBfqDdI-xwVNeVx"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 //data pin is connected to d2 on dhp
#define DHTTYPE DHT11 // name the sensor as an object

char auth[] = "H5iLXkZm_Rv-aY0ntBBfqDdI-xwVNeVx";
char ssid[] = "S";
char pass[] = "12345678";

DHT dht(DHTPIN, DHTTYPE);


void setup ()
{
  Serial.begin(9600);
  Serial.println("DHT test Successfull!");
  Blynk.begin(auth,ssid,pass);
  Serial.println("Blynk connected successfully");
  dht.begin();
}

void loop()
{
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);
  if (isnan(h)|| isnan(t)|| isnan (f))
  {
    Serial.println("something is not working as intended");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("degrees celsius");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}
