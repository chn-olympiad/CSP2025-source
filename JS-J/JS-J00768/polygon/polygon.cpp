#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[5005];
ll ans;
ll x;
const ll mod=998244353;
void dfs(ll maxn,ll cnt,ll sum,ll pos){
	if(pos==n+1){
		if(cnt>=3 && sum>(2*maxn)){
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(max(maxn,a[pos]),cnt+1,sum+a[pos],pos+1);
	dfs(maxn,cnt,sum,pos+1);
	return;
}
ll q(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1){
			res=((res%mod)*(a%mod))%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		n>>=1;
	}
	return res%mod;
}
ll maxn1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
		maxn1=max(maxn1,a[i]);
	}
	if(maxn1==1 && n>20){
		for(ll i = 3;i<=n;i++){
			ll x1=1;
			ll y1=1;
			for(ll j=n;j>=(n-i+1);j--){
				x1=(x1*j)%mod;
			}
			for(ll j = 1;j<=i;j++){
				y1=(y1*j)%mod;
			}
			ll z1=1;
			z1=(x1*q(y1,mod-2))%mod;
			ans=(ans+z1)%mod;
		}
		cout<<ans%mod<<'\n';
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans%mod;
	return 0;
}