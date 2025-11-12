#include <bits/stdc++.h>
using namespace std;
int n,k,a[1010],dp[1010][1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int l=i;l<=j;l++)
			{
				sum^=a[l];
			}
			if(sum==k)
			{
				dp[i][j]++;
			}
		}
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			for(int q=i;q<j;q++)
			{
				dp[i][j]=max(dp[i][j],dp[i][q]+dp[q+1][j]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
