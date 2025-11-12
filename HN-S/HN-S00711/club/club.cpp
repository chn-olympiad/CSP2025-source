#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, a[100005], b[100005], c[100005];
bool cmp(int a, int b)
{
	return a > b;
}
void dfs(int i, int x, int y, int z, int sum)
{
	if (i > n)
	{
		ans = max(ans, sum);
		return ;
	}
	if (x < (n >> 1)) dfs(i + 1, x + 1, y, x, sum + a[i]);
	if (y < (n >> 1)) dfs(i + 1, x, y + 1, z, sum + b[i]);
	if (z < (n >> 1)) dfs(i + 1, x, y, z + 1, sum + c[i]);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T --)
	{
		ans = 0;
		cin >> n;
		bool fa = 1, fb = 1;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0 || c[i] != 0) fa = 0;
			if (c[i] != 0) fb = 0;
		}
		if (fa)
		{
			sort(a + 1, a + n + 1, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i ++)
				ans += a[i];
			cout << ans << endl;
		}
		else 
		{
			dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
		}
	}
	return 0;
 } 
