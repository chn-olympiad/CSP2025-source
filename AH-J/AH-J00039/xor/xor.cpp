#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[500005];
ll ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll tem=a[1];
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			tem=a[i+1];
			continue;
		}
		if(a[i]==tem)continue;
		tem=tem xor a[i];
		if(tem==k){
			ans++;
			tem=a[i+1];
		}
	}
	printf("%lld",ans);
	return 0;
}
