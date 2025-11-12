#include<bits/stdc++.h>
using namespace std;
const long long mods=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	int a[n];
	bool all1=true;
	cin>>s;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			all1=false;
			break;
		}
	}
	if(all1){
		long long ans=1;
		for(int i=1;i<=500;i++){
			ans*=i;
			ans%=mods;
			cout<<ans;
		}
	}
	/*
	else{
		
	}
	*/
	return 0;
} 
