#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500002];
int dp[1001][1001];
bool ch[1001][1001];//从l到r区间内，能够满足的最大值 
bool check(int i, int j)
{
	int sum=a[i];
	for(int p=i+1;p<=j;p++)
	{
		sum^=a[p];
	}
	if(sum==k)
	{
		return 1;
	}
	return 0;
}
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
			ch[i][j]=check(i,j);
		}
	}
	for(int r=1;r<=n;r++)
	{
		for(int i=1;i<=r;i++)
		{
			dp[1][r]=max(dp[1][r],dp[1][i-1]+ch[i][r]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}