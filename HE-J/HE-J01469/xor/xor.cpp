#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[600000];
int dp[10000][10000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i<n;i++)
	{
		dp[i][i] = a[i];
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			dp[i][j] = dp[i][j-1]^a[j];
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			if(dp[i][j] == k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
