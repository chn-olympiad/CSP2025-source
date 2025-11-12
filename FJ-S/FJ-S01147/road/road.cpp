#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[5][100007], a[17][100007], b[1007][1007][4], c[17], ans;
int main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m, i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		a[u[i]][v[i]][1] = 1;
		a[v[i]][u[i]][1] = 1;
		a[u[i]][v[i]][2] = w[i];
		a[v[i]][u[i]][2] = w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m, i++)
	{
		
		for (int j = 1; j <= i, j++)
		{
			if (b[i][j][1] = 0)
			{
				int minn = 9999999;
				for (int l = 1; l <= k; l++)
				{
					minn = min (minn, c[l] + a[l][i] + a[l][j]);
				}
				ans += min(minn, a[i][j][2]);
			}
		}
	}
	cout << ans;
	return 0;
}
