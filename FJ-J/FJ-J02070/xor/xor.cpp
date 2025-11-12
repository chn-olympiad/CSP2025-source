#include<bits/stdc++.h>
using namespace std;
int a[500001];
int b[500001];
int dp[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int n,k,i,j;
cin>>n>>k;
for(i=1;i<=n;i++)
{
	cin>>a[i];
	b[i]=(b[i-1]^a[i]);
}
for(i=1;i<=n;i++)
{dp[i]=dp[i-1];
	for(j=i;j>=0;j--)
	{
		if((b[i]^b[j])==k&&i!=j)
		{
			dp[i]=max(dp[j]+1,dp[i]);
			break;
		}
		if(i==j&&a[i]==k)
		{
			dp[i]=max(dp[i],dp[i-1]+1);
			break;
		}
	}
}cout<<dp[n];
}

