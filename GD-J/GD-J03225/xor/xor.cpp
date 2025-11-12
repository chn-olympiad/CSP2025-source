#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]^a[i];
	int ans=0,r=1,l=1;
	while(r<=n){
		for(int i=r;i>=l;i--){
			if((sum[r]^sum[i-1])==k){
				ans++;l=r+1;break;
			}
		}
		r++;
	}
	printf("%lld\n",ans);
	return 0;
}
