#include<iostream>
#include<fstream>
#include<ctime>
using namespace std ;
int main(){
	ifstream cin ("employ.in" ) ;
	ofstream cout("employ.out") ;
	cout << (int(time(NULL))&1) << endl ;
	return 0 ;
}