#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+10;
int a[N],s[N],k,dp[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int now=s[i-1]^s[j];
			if(now==k)
			dp[j]=max(dp[i-1]+1,dp[j]);
			else
			dp[j]=max(dp[i-1],dp[j]);
		}
	}
	cout<<dp[n];
	return 0;
}
