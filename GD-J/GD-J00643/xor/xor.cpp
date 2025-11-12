#include<iostream>
using namespace std;
const int MAXN=1e4+10;
int n,sum[MAXN],x,dp[MAXN][MAXN],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if((sum[r]^sum[l-1])==k)
			{
				dp[l][r]++;
			}
		}
	}
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l<=n-len;l++)
		{
			for(int k=l;k<l+len;k++)
			{
				dp[l][l+len]=max(dp[l][l+len],dp[l][k]+dp[k+1][l+len]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
