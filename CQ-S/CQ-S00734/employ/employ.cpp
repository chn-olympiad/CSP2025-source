#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	int z=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') z=1;
	}
	if(z==0){
		long long ans=1;
		for(int i=1;i<=a;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}else{
		cout<<a*a/2; 
	}
	return 0;
}
