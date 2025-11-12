#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,q;
int sum[500005],dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int sc;
		scanf("%d",&sc);
		sum[i]=sum[i-1] xor sc;
		q+=sc;
//		printf("%d ",sum[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(dp[j]!=dp[i-1])
			{
				break;
			}
			int xo=sum[i] xor sum[j];
			if(xo==m)
			{
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
			else
			{
				dp[i]=max(dp[i],dp[j]);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
