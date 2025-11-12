#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll N=2e5+7,M=5e6+7,mod=9085415445289,bs=1331;
string s,t;//,s1[N],t1[N];
ll a[N],b[N],c[N],d[M],e[M],h[M]={1};
pii pa[N],pb[N];
ll n,m,k,q,ans,cnt,sum,tot,opt,mx=-1e9,l,r,mid,f,x,y,z,tmp;
ll gtd(ll l,ll r){
	if(r<0)return 0;
	if(!l)return d[r];
	return (d[r]-d[l-1]*h[r-l+1]%mod+mod)%mod;
}
ll gte(ll l,ll r){
	if(r<0)return 0;
	if(!l)return e[r];
	return (e[r]-e[l-1]*h[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s>>t,a[i]=s.size();//,s1[i]=s,t1[i]=t;
		for(ll j=0;j<s.size();j++){
			b[i]=(b[i]*bs+s[j]-'a')%mod;
			if(s[j]>'b')f=1;
			if(s[j]=='b')x=j;
		}
		for(ll j=0;j<t.size();j++){
			c[i]=(c[i]*bs+t[j]-'a')%mod;
			if(t[j]>'b')f=1;
			if(t[j]=='b')y=j;
		}
		pa[i]={x,s.size()-x},pb[i]={y,t.size()-y};
	}
	if(!f){
		while(m--){
			cin>>s>>t,ans=0;
			if(s.size()!=t.size()){
				cout<<"0\n";continue;
			}
			for(ll j=0;j<s.size();j++)if(s[j]=='b')x=j;
			for(ll j=0;j<t.size();j++)if(t[j]=='b')y=j;
			for(ll i=1;i<=n;i++){
				if(pa[i].first-pb[i].first!=x-y)continue;
				if(x>=pa[i].first&&s.size()-x>=pa[i].second&&y>=pb[i].first&&t.size()-y>=pb[i].second)ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(ll i=1;i<=5e6;i++)h[i]=h[i-1]*bs%mod;
	while(m--){
		cin>>s>>t,ans=0;//,tmp++;
		if(s.size()!=t.size()){
			cout<<"0\n";continue;
		}
//		if(tmp==101){
//			cout<<s<<"\n"<<t<<"\n";
//		}
//		else continue;
		for(ll j=0;j<s.size();j++){
			d[j]=(d[j-1]*bs+s[j]-'a')%mod;
			e[j]=(e[j-1]*bs+t[j]-'a')%mod;
		}
		for(ll i=0;i<s.size();i++){
			for(ll j=1;j<=n;j++){
				if(a[j]<=s.size()-i){
//					ans+=(s.substr(0,i-1)+s1[j]+s.substr(i+a[j],s.size()-1-i-a[j]))
					if(gtd(i,i+a[j]-1)==b[j]&&gte(i,i+a[j]-1)==c[j]){
						if(gtd(0,i-1)==gte(0,i-1)&&gtd(i+a[j],s.size()-1)==gte(i+a[j],s.size()-1))ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
2 10
hsfsd dfshg
aahsfsda aadfshga
hsfsd dfshg
aahsfsda aadfshga
aaaahsfsda aaaadfshga
*/
