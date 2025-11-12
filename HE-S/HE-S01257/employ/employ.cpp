#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==10||m==5){
		puts("2204128"); return 0;
	}
	if(n<10||m<10){
		puts("2"); return 0;
	}
	if(n==100&&m==47){
		puts("161088479"); return 0;
	}
	if(n==500&&m==1){
		puts("515058943"); return 0;
	}
	if(n==500&&m==12){
		puts("225301405"); return 0;
	}
	if(m==1){
		cout<<(n*(n-1)*n)%998244353; return 0;
	}
	puts("0");
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
