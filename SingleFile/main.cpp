#include <iostream>
#include <string>
using namespace std;

unsigned short ReadPersonAge() {
	cout << "Type somebody's age: ";
	unsigned short in;
	cin >> in;
	return in;
};

string ReadPersonName() {
	cout << "Type somebody's name: ";
	string in;
	cin >> in;
	return in;
};

unsigned short global_height;

void ReadPersonHeight() {
	cout << "Type somebody's height: ";
	cin >> global_height;
};

void ReadPersonWeight(unsigned short& out) {
	cout << "Type somebody's weight: ";
	cin >> out;
};

void ReadPersonSalary(double* out) {
	cout << "Type somebody's salary: ";
	cin >> *out;
};

void ReadPersonData(string& name, unsigned short& age, double& salary) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonSalary(&salary);
};

void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonHeight();
	height = global_height;
	ReadPersonWeight(weight);
};

void WritePersonData(const string& name, const unsigned short age, const string& height = "", const string& weight = "", const string& salary = "") {
	cout << "  == Showing summary ==" << endl;
	cout << "Name is:   " << name << endl;
	cout << "Age is:    " << age << endl;
	if (!height.empty()) cout << "Height is: " << height << endl;
	if (!weight.empty()) cout << "Weight is: " << weight << endl;
	if (!salary.empty()) cout << "Salary is: " << salary << endl;
};

int main(int argc, char** argv) {
	string name;
	unsigned short age, height, weight;
	double salary;
	ReadPersonData(name, age, salary);
	WritePersonData(name, age, "", "", to_string(salary));
	ReadPersonData(name, age, height, weight);
	WritePersonData(name, age, to_string(height), to_string(weight));
};