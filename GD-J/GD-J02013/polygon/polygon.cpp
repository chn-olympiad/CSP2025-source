#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ans, n, a[5005];
bool vis[5005];
void dfs(int step)
{
	if (step == n + 1)
	{
		long long cnt = 0, maxx = 0;
		for (int i = 1; i <= n; i ++)
			if (vis[i])
			{
				cnt += a[i];
				maxx = max(maxx, a[i]);
			}
		if (cnt > 2 * maxx)
			ans = (ans + 1) % mod;
		return;
	}
	vis[step] = 1;
	dfs(step + 1);
	vis[step] = 0;
	dfs(step + 1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
