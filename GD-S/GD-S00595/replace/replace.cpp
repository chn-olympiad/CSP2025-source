#include<iostream>
#include<map>
#include<cstring>
using namespace std;
#define ll long long
const ll m1=1000000103,m2=1000000007,m3=1000000009,k=37,n1=432432477;
ll n,q;
map<ll,ll>mp1,mp2;
ll ny(ll mod){
	ll w=mod-2,re=1,x=k;
	while(w){
		if(w%2)re*=x;
		re%=mod;x=x*x%mod;w/=2;
	}
	return re;
}
ll ksm(ll x,ll w){
	ll re=1;
	while(w){
		if(w%2)re*=x;
		re%=m1;x=x*x%m1;w/=2;
	}
	return re;
}
ll hs(string a,ll mod){
	ll re=0;
	for(ll i=0;i<a.size();i++){
		re*=k;
		re+=(a[i]-'a'+1);
		re%=mod;
	}
	return re;
}
ll h1[5100],h2[5100],len;
void pts20(){
	string s1,s2;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		mp1[hs(s1,m1)]=i;
		mp2[hs(s2,m1)]=i;
	}
	while(q--){
		cin>>s1>>s2;
		len=s1.size();
		for(ll i=1;i<=len;i++){
			h1[i]=(h1[i-1]*k+(s1[i-1]-'a'+1))%m1;
			h2[i]=(h2[i-1]*k+(s2[i-1]-'a'+1))%m1;
		}
		ll l=-1,r=0;
		for(ll i=0;i<len;i++){
			if(s1[i]!=s2[i]){
				if(l==-1)l=i+1;
				r=i+1;
			}
		}
		ll ans=0;
		for(ll i=1;i<=l;i++){
			for(ll j=r;j<=len;j++){
				ll w=i-1,o=ksm(k,w);
				ll x1=(h1[j]-h1[i-1]*o%m1+m1)%m1,x2=(h2[j]-h2[i-1]*o%m1+m1)%m1;
				if(mp1.count(x1)&&mp2.count(x2)){
					if(mp1[x1]==mp2[x2]){
						ans++;
					}//cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	pts20();
	return 0;
}
