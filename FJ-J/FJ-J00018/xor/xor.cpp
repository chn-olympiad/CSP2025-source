#include<bits/stdc++.h>
using namespace std;
int a[500005];
int dp[5005][5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int d=i;d<n;d++)
		{
			int l;
			for(int j=i;j<=d;j++)
			{
				if(j==i)
				l=a[j];
				else
				l^=a[j];
			}
			if(l==k)
			dp[i][d]++;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int d=i+1;d<n;d++)
		{
			for(int j=i;j<=d;j++)
			{
				dp[i][d]=max(dp[i][d],dp[i][j]+dp[j+1][d]);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
