#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],cnt,maxx;
ll qpow(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a%mod;
	ll x=qpow(a,b/2);
	if(b%2) return x*x%mod*a%mod;
	return x*x%mod;
}
ll dfs(ll x,ll maxx,ll cnt){
	if(x==n+1){
		if(cnt>maxx*2) return 1;
		return 0;
	}
	return dfs(x+1,max(maxx,a[x]),cnt+a[x])+dfs(x+1,maxx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxx=max(maxx,a[i]);
	if(maxx==1){
		ll s=((qpow(2,n)-n-n*(n+1)%mod/2)%mod+mod)%mod;
		cout<<s<<"\n";
	}
	else cout<<dfs(1,0,0)<<"\n";

	return 0;
}
