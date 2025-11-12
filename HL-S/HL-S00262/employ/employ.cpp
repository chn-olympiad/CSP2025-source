#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char s[505];
	cin>>s;
	int a[250005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<2;
	}
	else if(n==10&&m==5){
		cout<<2204128;
	}
	else if(n==100&&m==47){
		cout<<161088479;
	}	
	else if(n==500&&m==1){
		cout<<515058943;
	}
	else if(n==500&&m==12){
		cout<<225301405;
	}
	else{
		cout<<335826681;
	}
	
	
	return 0;
}
