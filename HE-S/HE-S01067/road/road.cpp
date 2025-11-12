#include <bits/stdc++.h>
using namespace std;
const int A = 1e6 + 10;
int ans, k, m, n, u[A], v[A], w[A];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		cin >> u[i] >> v[i] >> w[i], ans += w[i];
	cout << ans;
	return 0;
}
