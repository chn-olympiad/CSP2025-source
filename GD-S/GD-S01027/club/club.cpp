#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int t, n, a[N], b[N], c[N], ans;
void dfs(int step, int sum, int x, int y, int z)
{
	if (step > n)
	{
		ans = max(sum, ans);
		return;
	}
	if (x < n / 2)
		dfs(step + 1, sum + a[step], x + 1, y, z);
	if (y < n / 2)
		dfs(step + 1, sum + b[step], x, y + 1, z);
	if (z < n / 2)
		dfs(step + 1, sum + c[step], x, y, z + 1);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
