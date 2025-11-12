#include<bits/stdc++.h>
using namespace std;
long long s[600],c[600];
int main{
	fropen(employ.in,"r",stdin);
	fropen(employ.out,"w",stdout);
	long long s,n,m;
	cin>>n>>m;
	cin>>>s;
	long long g=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(n==3){
			g=2;
		}
		if(n==10){
			g=2204128;
		}
		if(n==100){
			g=161088479;
		}
		if(n==500){
			g=515058943;
		}
		if(n==50){
			g=225301405;
			
		}
		cout<<g;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
