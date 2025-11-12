#include <bits/stdc++.h>
using namespace std;
int m, n, k, c[15], u[100005], v[100005], w[100005], a[15][100005], l[100005], t, num;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = k; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	sort(w + 1, w + m + 1);
	for(int i = 1; i <= n - 1; i++)
	{
		num+=w[i];
	}
	cout << num;
	return 0;
}
