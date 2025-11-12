#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500005],sum[500005],dp[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k) dp[i]=max(dp[i],dp[j-1]+1);
			else dp[i]=max(dp[i],dp[j-1]);
		}
	}
//	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<dp[n];
	return 0;
}
/*4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3*/