#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N],dp[N];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]); 
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mp.count(sum[i]^m)||(sum[i]^m)==0) dp[i]=max(dp[i],dp[mp[sum[i]^m]]+1);
		mp[sum[i]]=i;
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}
