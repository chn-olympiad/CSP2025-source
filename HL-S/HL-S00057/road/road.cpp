#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	int u[m], v[m], w[m], c[k], a[n];
	for(int i = 0; i < m; i ++) cin >> u[i] >> v[i] >> w[i];
	for(int i = 0; i < k; i ++)
	{
		cin >> c[i];
		for(int i = 0; i < n; i ++) cin >> a[i];
	}
	sort(w, w + m);
	for(int i = 0; i < n - 1; i ++) ans += w[i];
	cout << ans;
	return 0;
}