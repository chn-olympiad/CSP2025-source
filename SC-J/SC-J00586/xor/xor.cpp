#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],sum[maxn],dp[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(sum[i]^sum[j-1]==k)
			 dp[i]=max(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
 } 