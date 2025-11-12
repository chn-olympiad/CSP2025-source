#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001],sum[500001],dp[500001];
bool x[500001];
vector<int> g[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]),sum[i]=(sum[i-1]^a[i]);
		for(int l=i-1,r=i;l>=1;l--)
			if((sum[r]^sum[l-1])==k)
			{
				g[r].push_back(l);
				x[r]=true;
				break;
			}
		if(a[i]==k) g[i].push_back(i),x[i]=true;
	}
	for(int r=1;r<=n;r++)
	{
		dp[r]=dp[r-1];
		if(x[r])
		{
			for(int j=0;j<g[r].size();j++)
			{
				int l=g[r][j];
				dp[r]=max(dp[r],dp[l-1]+1);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
