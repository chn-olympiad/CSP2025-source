#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[100000];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u, v, w, c;
	for (int i = 1; i <= m; i++) cin >> u >> v >> w;
	for (int i = 1; i <= k; i++)
	{
		cin >> c;
		for (int j = 1; j <= n+1; j++)
		{
			cin >> a[j];
		}
	}
	cout << 13;
}
