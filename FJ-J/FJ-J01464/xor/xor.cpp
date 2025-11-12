#include<bits/stdc++.h>
using namespace std;
int n,k,a[514514],v[514514],sum[514514],dp[514514];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	sum[i]=sum[i-1]^a[i];
	v[sum[i]]=i;
	dp[i]=dp[i-1];
	if(v[sum[i]^k])
	dp[i]=max(dp[i],dp[v[sum[i]^k]]+1);
} 
cout<<dp[n];
return 0;
}

