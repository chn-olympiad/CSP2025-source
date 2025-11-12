#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100086],ans,a1;
const ll mod=998244353;
void dfs(ll i,ll sum,ll maxx,ll s){
	if(s>=3&&sum>maxx*2) ans++,ans%=mod;
	for(ll j=i+1;j<=n;j++){
		dfs(j,sum+a[j],max(maxx,a[j]),s+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
	}
	if(a1==n){
		for(ll i=3;i<=n;i++){
			vector<ll> v1,v2;
			for(ll j=1;j<=i;j++){
				v1.push_back(j),v2.push_back(n-j+1);
			}
			ll mul=1;
			for(ll j=0;j<i;j++){
				//v1[j]»¯¼ò
				for(ll k=0;k<i;k++){
					if(__gcd(v1[j],v2[k])!=1){
						ll gcd=__gcd(v1[j],v2[k]);
						v1[j]/=gcd;
						v2[k]/=gcd;
						if(v1[j]==1) break;
					}
				}
			}
			for(ll j=0;j<i;j++){
				mul*=v2[j],mul%=mod;
			}
			ans+=mul;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
