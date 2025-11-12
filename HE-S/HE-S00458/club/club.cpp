#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[100010][4], b[100010];
ll ans;

void dfs(int step, int c1, int c2, int c3, ll sum)
{
	if (step > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (c1 < n / 2) dfs(step + 1, c1+1, c2, c3, sum + a[step][1]);
	if (c2 < n / 2) dfs(step + 1, c1, c2+1, c3, sum + a[step][2]);
	if (c3 < n / 2) dfs(step + 1, c1, c2, c3+1, sum + a[step][3]);
}

bool cmp(int x, int y)
{
	return x > y;
}

void solve()
{
	ans = 0;
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
		if (a[i][2] != 0 || a[i][3] != 0) flag = false;
	}
	if (flag)
	{
		for (int i = 1; i <= n; i++) b[i] = a[i][1];
		sort(b + 1, b + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			ans += b[i];
		cout << ans << endl;
		return;
	}
	dfs(1, 0, 0, 0, 0);
	cout << ans << endl;
	return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
