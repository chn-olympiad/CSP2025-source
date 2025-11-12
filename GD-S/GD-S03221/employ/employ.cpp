#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],x,xx,t,ans=1,mod=998244353; 
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') x=1;
		else t++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			xx=1;
		}
	}
	if(xx==0){
		cout<<0;
	}else if(x==0){
		for(int i=s.size();i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}

