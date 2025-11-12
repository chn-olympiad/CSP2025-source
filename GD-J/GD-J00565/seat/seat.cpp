#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
//using namespace std;
std::ifstream fin("seat.in");
std::ofstream fout("seat.out");

int main(){
	short n,m,t;
	fin>>n>>m;
	t = n*m;
	std::vector<short> grades(t);
	for(short i = 0;i < t;i++)
		fin>>grades[i];
		
	char mygrade = grades[0];
	
	std::sort(grades.begin(),grades.end(),std::greater<char>());
	
	short pai = 0;
	for(std::vector<short>::iterator i = grades.begin();i < grades.end();i++){
		if((*i) == mygrade){
			pai = i - grades.begin();
			break; 
		}
	}
	
	if(((pai / n) % 2) == 0){
		fout<<pai / n + 1<<' '<<pai % n + 1;
	}
	else{
		fout<<pai / n + 1<<' '<<m - pai % n;
	}
	return 0; 
	
}
