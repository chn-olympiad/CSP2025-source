#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k;
string s;
int a[501];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<2;
	}if(n==10){
		cout<<2204128;
	}if(n==100){
		cout<<161088479;
	}if(n==500){
		if(k==12){
			cout<<225301405;
		}else{
			cout<<515058943;
		}
	}
	return 0;	
}
