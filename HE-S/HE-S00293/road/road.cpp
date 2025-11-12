#include<bits/stdc++.h>
using namespace std;
long long mp[10005][10005],c[15],mp2[15][10005],dp[10005][10005],sum = 0;
bool f[10005][10005],c2[15],f2[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	memset(mp,0x3f,sizeof(mp));
	memset(f,false,sizeof(f));
	for(int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		mp[u][v] = w;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> mp2[i][j]; 
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int kk = 1; kk <= n; kk++)
			{
				dp[i][j] = min(mp[i][j],mp[i][kk] + mp[kk][j]);
				for(int l = 1; l <= k; l++)
				{
					dp[i][j] = min(dp[i][j],c[l] + mp2[l][i] + mp2[l][j]);
				}
			}
			for(int kk = 1; kk <= n; kk++)
			{
				for(int l = 1; l <= k; l++)
				{
					if(dp[i][j] == mp[i][j]) f[i][j] = true;
					if(dp[i][j] == mp[i][kk] + mp[kk][j]) f[i][k] = true,f[k][j] = true;
					if(dp[i][j] == c[l] + mp2[l][i] + mp2[l][j]) c2[l] = true,f[l][i] = true,f[l][j] = true;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(f[i][j]) sum += mp[i][j];
		}
	}
	for(int i = 1; i <= k; i++)
	{
		if(c2[i]) sum += c[i];
		for(int j = 1; j <= n; j++)
		{
			if(f2[i][j]) sum += mp2[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}
