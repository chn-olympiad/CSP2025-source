#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],x[N];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++) x[i]=x[i-1]^a[i];
	ll ans=0;
	printf("%lld",n);
	return 0;
}
