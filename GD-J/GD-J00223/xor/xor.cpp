#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005];
int b[10005][10005],dp[10005];
int My_max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		b[i][i]=sum;
		for(int j=i+1;j<=n;j++)
		{
			sum^=a[j];
			b[i][j]=sum;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++)
		{
			if(b[j][i]==k)
			{
				dp[i]=My_max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}

