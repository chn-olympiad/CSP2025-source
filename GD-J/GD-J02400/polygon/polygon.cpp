#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
const ll mod=998244353;
ll n;
ll a[N];
ll tim[N];
ll ans;
ll qpow(ll x,ll b){
	if(b==0LL) return 1LL;
	ll res=1LL;
	while(b){
		if(b&1LL) res=(res*x)%mod;
		x=(x*x)%mod;
		b>>=1;
	}
	return res;
}
ll C(ll u,ll v){
	return (tim[u]*qpow(tim[v],mod-2)%mod)*qpow(tim[u-v],mod-2)%mod;
}
ll dfs(ll x,ll mxid,ll mx,ll all,ll stk){
	if(all>mx) return 0LL;
	if(x>n) return 0LL;
	ll res=0;
	if(stk>=2) res++;
	for(ll i=x;i<=mxid;i++){
		if(i==mxid) continue;
		res=(res+dfs(i+1,mxid,mx,all+a[i],stk+1))%mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	tim[0]=1;
	ll mxxx=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		tim[i]=(tim[i-1]*i)%mod;
		mxxx=max(mxxx,a[i]);
	}
	if(mxxx<=1){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==1LL) cnt++;
		}
		for(ll i=3;i<=cnt;i++){
			ans=(ans+C(cnt,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=3;i<=n;i++){
		ans=(ans+C(n,i))%mod;
	}
	for(ll i=1;i<=n;i++){
		int k=dfs(1LL,i,a[i],0LL,0LL);
		ans=((ans-k)%mod+mod)%mod;
	}
	//dfs(1LL,0LL,0LL);
	cout<<ans;
	return 0;
}
