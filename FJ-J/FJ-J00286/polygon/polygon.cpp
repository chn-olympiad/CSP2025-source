#include<bits/stdc++.h>
#define N 5010
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,a[N];
ll f[N],ans;
ll qmi(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+n); f[0]=1ll;
	for(int i=1;i<n;++i){
		for(int j=N-10;j>=a[i];--j) f[j]=(f[j]+f[j-a[i]])%mod;
		for(int j=0;j<=a[i+1];++j) ans=(ans+f[j])%mod;
//		for(int j=0;j<=15;++j) printf("%lld ",f[j]); puts("");
	}
	printf("%lld\n",((qmi(2ll,n)-ans-2ll)%mod+mod)%mod);
	return 0;
}
