#include <bits/stdc++.h>
using namespace std;
int n, m, k, w[1000005], ans;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int u, v;
		scanf("%d%d%d", &u, &v, &w[i]);
	}
	sort(w + 1, w + n + 1);
	for (int i = 1;i < n;i++)
		ans += w[i];
	cout << ans;
	return 0;
}
