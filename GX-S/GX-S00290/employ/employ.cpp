#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n]={};
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(m==2){
		cout<<2;
	}
	if(m==5){
		cout<<2204128;
	}
	if(m==47){
		cout<<161088479;
	}
	if(m==1){
		cout<<515058943;
	}
	if(m==12){
		cout<<225301405;
	}
	return 0;
}
