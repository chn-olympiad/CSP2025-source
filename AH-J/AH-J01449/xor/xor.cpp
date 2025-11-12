#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll n,k,cnt,a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll ans=sum[i-1]^sum[j];
			if(ans==k) cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
