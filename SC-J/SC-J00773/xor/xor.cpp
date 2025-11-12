#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--)
		{
			if((b[j]^b[i])==k)
			{
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}