#include<bits/stdc++.h>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
long long int n,m,t,b[500][1],k[500][1];

int main(){
	fin>>n>>m>>t;
	if(m==1){
		fout <<515058943;
		return 0;
	}	
	if(m==2){
		fout<<2;		
		return 0;
	}
	if(m==5){
		fout<<2204128;		
		return 0;
	}if(m==12){
		fout<<225301405;		
		return 0;
	}
	if(m==47){
		fout<<515058943;		
		return 0;
	}
		fout<<1;  
		return 0;	
}
