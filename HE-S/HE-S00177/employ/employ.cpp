#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char s[510];
int c[510];
bool f=0,f2=0;
int cnt0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1')f2=1;
	}for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)f=1;
		if(c[i]==0)cnt0++;
	}
	if(!f)cout<<0;
	else{
		if(n-cnt0<m)cout<<0;
		else{
			long long ans=1;
			for(int i=1;i<=n-cnt0;i++)ans=(ans*i)%mod;
			cout<<ans;
		}
	}
	return 0;
}
