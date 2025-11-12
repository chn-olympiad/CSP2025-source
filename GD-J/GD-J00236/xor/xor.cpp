#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,dp[500005],a[500005],JL[4200005],ans;
signed main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) a[i]^=a[i-1];
	memset(JL,-63,sizeof(JL)),JL[0]=0;
	for(int i=1;i<=n;i++)
		dp[i]=max(max(JL[a[i]^k]+1,0ll),dp[i-1]),JL[a[i]]=max(JL[a[i]],dp[i]),ans=max(ans,dp[i]);
	return printf("%lld\n",ans),0;
}
