#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005];
int dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
		b[i]=a[i]^b[i-1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(b[i]==k) dp[i]=max(dp[i],1);
		for(int j=1;j<i;j++)
		{
			int t=b[i]^b[j];
			if(t==k)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
