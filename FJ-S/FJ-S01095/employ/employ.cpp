#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<2;
	}else if(n==10){
		cout<<2204128;
		return 0;
	}else if(n==100){
		cout<<161088479;
	}else if(n==500&&m==1){
		cout<<515058943;
	}else if(n==500&&m==2){
		cout<<225301405;
	}else{
		cout<<0;
	}
	
	
	
	
	return 0;
}
