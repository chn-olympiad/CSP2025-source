#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100000+10;
ll T,n,a1[N],a2[N],a3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		for(ll i=1;i<=n;i++){
			a1[i]=0;
			a2[i]=0;
			a3[i]=0;
		}
		ll ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
		}
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		for(ll i=n;i>n/2;i--){
			ans+=a1[i];
		}
		for(ll i=n/2;i>=1;i--){
			ans+=a2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
