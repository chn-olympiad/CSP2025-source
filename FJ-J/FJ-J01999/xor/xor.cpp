#include<bits/stdc++.h>
#define ll long long
#define MAXN 500005
using namespace std;
ll n,k,a[MAXN],sum[MAXN],dp[MAXN],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if((sum[i]^sum[j-1])==k)
				dp[i]=max(dp[i],dp[j-1]+1);
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;		
}
