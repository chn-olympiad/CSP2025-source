#include <bits/stdc++.h>
using namespace std;
int n,k,dp[500001],a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=dp[i-1];
		int sum=0;
		for(int j=i;j>=1;j--)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
