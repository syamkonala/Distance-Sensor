// Define the pins for the ultrasonic sensor
#define trigPin 2
#define echoPin 3

// Define the pin for the speaker
#define speakerPin 4

// Define the maximum distance (in centimeters) to trigger the alarm
#define maxDistance 50

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert the duration into centimeters

  if (distance <= maxDistance && distance > 0) {
    // Object detected within the specified range
    tone(speakerPin, 1000); // Generate a tone of 1000 Hz
    delay(200); // Adjust the duration of the tone
    noTone(speakerPin); // Turn off the tone
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    noTone(speakerPin); // Turn off the tone
  }
  delay(500); // Adjust the frequency of distance measurements
}