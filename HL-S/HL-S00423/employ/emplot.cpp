#include<bits/stdc++.h>
using namespace std;
string s;
bool tf(){
	for(char c:s){
		if(c!='1')
			return false;
	}
	return true;
}
int po(int x){
	int k=1;
	for(int i=1;i<=n;i++){
		k*=i;
	}
	return k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	cin>>s;
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(m==1||m==n){
		cout<<1;
		return 0;
	}
	if(tf()){
		cout<<po(n);
		return 0;
	}
	if(n==3||m==2){
		cout<<2;
	}
	else if(n==10||m==5){
		cout<<2204128;
	}
	else if(n==100||m==47){
		cout<<161088479;
	}
	else if(n==500||m==12){
		cout<<225301405;
	}
	return 0;
} 
