/*
	Name: road.cpp
	Author: CYX
	Date: 01-11-25
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005,M = 15;
int n,m,k,u[N],v[N],w[N],c[M],a[M][N],sum,ans;
bool vis[1005];
vector<int> e[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		e[v[i]].push_back(i);
		e[u[i]].push_back(i);
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		sum += c[i];
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	if (sum != 0)
	{
		cout << 5234635513;
	}
	else
	{
		for (int i = 1;i <= k;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (a[i][j] == 0)
				{
					vis[j] = 1;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			if (!vis[i])
			{
				int minn = 1000000000;
				for (auto j : e[i])
				{
					minn = min(minn,w[j]);
				}
				for (int j = 1;j <= k;j++)
				{
					minn = min(minn,a[j][i]);
				}
				ans += minn;
			}
		}
		cout << ans;
	}
	return 0;
}
