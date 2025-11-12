#include<bits/stdc++.h>
using namespace std;

int num[500010],qz[500010],n,k,dp[500010],vis[500010],G[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(qz,0,sizeof(qz));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		qz[i]=qz[i-1]^num[i];
	}

	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if((qz[i]^qz[j])==k)
			{
				G[i]=j+1;
				vis[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)	dp[i]=max(dp[i-1],dp[G[i]-1]+1);
		else dp[i]==dp[i-1];
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
