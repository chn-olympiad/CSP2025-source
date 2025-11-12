#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+1]={0};
	int y[n+1][n+1]={0};
	for(int i=1;i<=n;i++)  
	{
		cin>>a[i];
		for(int j=1;j<=i-1;j++)
		{
			y[j][i]=y[j][i-1]^a[i];
		}
		y[i][i]=a[i];
	}
	bool yn[n+1][n+1]={false};
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(y[i][j]==k) yn[i][j]=true;
		}
	}
	int dp[n+1]={0};
	if(y[1][1]==k) dp[1]=1; 
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<=i-1;j++)
		{
			if(yn[j][i]==true)
			{
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
//¸øµã·Ö°É 
