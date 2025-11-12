#include<bits/stdc++.h>
using namespace std;
long long n,x,a[500010],dp[110][110];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==x)
		{
			dp[i][i]=1;
		}
		a[i]=a[i]^a[i-1];
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if((a[j]^a[i-1])==x)
				dp[i][j]=1;
			for(int k=i;k<j;k++)			
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);		
		}
	}
	cout<<dp[1][n]<<'\n';
	return 0;
}
