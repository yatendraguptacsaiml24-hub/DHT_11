#include <Arduino.h>
#include <DHT.h>
#define  DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // write your initialization code here
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT Sensor Initialized");

}
void loop() {
    // write your code here
    float humidity = dht.readHumidity();
    float tempreture = dht.readTemperature();
    if (isnan(humidity) || isnan(tempreture)){
        Serial.println("Failed to read from dht sensor!");
        delay(2000);
        return;
    }
    Serial.print("Humidity");
    Serial.print(humidity);
    Serial.print("% | ");
    Serial.print("Temperature");
    Serial.print(tempreture);
    Serial.println("C");
    delay(2000);


}