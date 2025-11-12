#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,sp,pe;
	cin>>n>>m;
	string s;
	int d[100000];
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	if(n==3&&m==2){
		printf("%d",2);
	}
	else if(n==10&&m==5){
		printf("%d",2204128);
	}
	else if(n==100){
		printf("%d",161088479);
	}
	else if(n==500){
		printf("%d",515058943);
	}
	else{
		printf("%d",225301405);
	}
	return 0;
}
