#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],tt;
long long ans,Mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)tt+=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m){
		int fl=1;
		if(tt!=n)fl=0;
		for(int i=1;i<=n;i++)if(c[i]==0)fl=0;
		if(fl){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%Mod;
			}
			cout<<ans;
		}
		else cout<<0;
	}
	return 0;
}
