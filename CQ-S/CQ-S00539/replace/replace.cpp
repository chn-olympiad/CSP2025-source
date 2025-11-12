#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=2e5+5,mod=1e9+7;
ll n,q,a[N],b[N],xx,yy,pw[N];
string s[N],ss[N],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;pw[0]=1;
	for(int i=1;i<=200000;i++) pw[i]=(pw[i-1]*29)%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		for(int j=0;j<s[i].size();j++) a[i]=(a[i]*29%mod+(s[i][j]-'a'))%mod;
		for(int j=0;j<ss[i].size();j++) b[i]=(b[i]*29%mod+(ss[i][j]-'a'))%mod;  
	}
	while(q--){
		ll ans=0;
		xx=0;yy=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<=x.size();i++) xx=(xx*29%mod+(x[i]-'a'))%mod;
		for(int i=0;i<=y.size();i++) yy=(yy*29%mod+(y[i]-'a'))%mod;
		for(int i=0;i<=x.size();i++){
			if(x[i]!=y[i]) continue;
			for(int j=1;j<=n;j++){
				if(x.size()-i-s[j].size()<0) continue;
				ll po=pw[x.size()-i-s[j].size()];
				ll pox=(po*a[j])%mod,poy=(po*b[j])%mod;
				if((xx-pox+mod)%mod==(yy-poy+mod)%mod) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

