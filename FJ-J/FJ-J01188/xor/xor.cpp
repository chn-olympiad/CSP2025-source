#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],sum[500005],ans,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j>=1;j--){
			if(j<=l) break;
			if((sum[i]^sum[j-1])==k){
				++ans;
				l=i;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
