#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
bool f;
ll n,a[5010],ans,c[5010],inv[5010];
void dfs(int d,int x,ll sum,ll ma) {
	if(sum>ma*2&&d>=3) ans=(ans+1)%mod;	
	if(x==n||d==n) return ;
	for(int i=x+1;i<=n;i++) 
		dfs(d+1,i,sum+a[i],max(ma,a[i]));
}
ll qpow(ll a,ll b){
	if(b==0) return 1;
	ll res=qpow(a,b/2)%mod;
	res=res*res%mod;
	if(b%2) res=res*a%mod;
	return res%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	c[0]=1,inv[0]=1;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=1) f=1;
		c[i]=c[i-1]*i%mod;
		inv[i]=qpow(c[i],mod-2)%mod;
	}
	if(f==0) {
		for(int i=3;i<=n;i++) {
			ans=(ans+c[n]%mod*inv[n-i]%mod*inv[i]%mod)%mod;
		}	
	}
	else dfs(0,0,0ll,0ll);
	printf("%lld",ans%mod);
	
	return 0;
}
