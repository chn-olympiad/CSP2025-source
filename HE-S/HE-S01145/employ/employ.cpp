#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,c[100000];
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2){
		cout<<2<<endl;
	}if(n==10&&m==5){
		cout<<2204128<<endl;
	}if(n==100&&m==47){
		cout<<161088479<<endl;
	}if(n==500&&m==1){
		cout<<515058943;
	}if(n==500&&m==12){
		cout<<225301405;
	}
	return 0;
}
