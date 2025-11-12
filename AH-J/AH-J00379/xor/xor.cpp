#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=1e6+5;
ll n,k,a[N],sum[N];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	ll ans=0;
	scanf ("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&a[i]);
		sum[i]=(ll)(sum[i-1]^a[i]);
	}
	//for (int i=1;i<=n;i++) cout<<sum[i]<<' ';
	int last=0;
	for (int i=1;i<=n;i++){	
		if (a[i]==k) {
			last=i;
			ans++;
			//cout<<i<<'\n';
			continue;
		}
		for (int l=i-1;l>last;l--){
			//if ((int)((num[i]-num[l]+1)&1) != (int)(k&1)) l++;
			
			if ((ll)(sum[i]^sum[l-1])==k){
				last=i;
				ans++;
				//cout<<i<<'\n';
			}
		}
		//cout<<l<<' '<<i<<' '<<ans<<'\n';
	}
	printf ("%lld",ans);
	return 0;
}
