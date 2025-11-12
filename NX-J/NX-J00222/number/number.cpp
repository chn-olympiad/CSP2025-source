//number.cpp
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
	int i , sizeofout ;
	ifstream in("number.in");
	string text ;
	char s[sizeof(text)] ;	
	while(getline(in,text)){
		for(i = 1 ; i <= sizeof(text) ; i++ ){
			s[i] = text[i];
		}
		
		sizeofout = sizeof(text);
	}
	
	
	char outtext[sizeof(text)] ;

	for(i=1 ; i <= sizeof(text) ; i++){
		if( int(s[i]) > 48 && int(s[i]) < 57 ){
			outtext[i] = s[i];
		}
		else{
			sizeofout-- ;
		}
	}

	ofstream out("number.out");
	for(i = 1 ; i <= sizeofout ; i++ ){
		out << outtext[i] ; 
	}
	return 0;
}
