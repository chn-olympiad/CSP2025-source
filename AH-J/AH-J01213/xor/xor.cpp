#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],xo;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==k)
	{
		dp[1]=1;
	}
	else
	{
		xo=a[1];
	}
	for(int i=2;i<=n;i++)
	{
		if(xo)
		{
			if(a[i]==k)
			{
				dp[i]=dp[i-1]+1;
				xo=0;
				continue;
			}
			xo^=a[i];
			if(xo==k)
			{
				xo=0;
				dp[i]=max(dp[i],dp[i-1]+1);
			}
			else
			{
				dp[i]=dp[i-1];
			}
		}
		else
		{
			if(a[i]==k)
			{
				dp[i]=dp[i-1]+1;
				continue;
			}
			xo=a[i];
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}
