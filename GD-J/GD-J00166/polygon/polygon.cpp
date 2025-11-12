#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans;
ll f(ll x){
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(mid>=x)r=mid-1;
		else l=mid+1;
	}
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			for(int k=j-1;k>=1;k--){
				if(a[k]+a[j]>a[i]){
					ans=(ans+(1<<k-1))%mod;
				}
				else{
					ll sum=a[j]+a[k];
					for(int l=k-1;l>=1;l--){
						sum+=a[l];
						if(sum>a[i]){
							ans=(ans+(1<<l-1))%mod;
							break;
						}
					}
					break;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
