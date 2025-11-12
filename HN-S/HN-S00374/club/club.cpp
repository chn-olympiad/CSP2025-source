#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct node{
	int n1, n2, n3, mid, maxi, mini, diff;
}a[N];
int n, m, cnt[5], ans;
bool cmp(node x, node y)
{
	return x.diff > y.diff;
}
bool AwA(node x, node y)
{
	return x.maxi > y.maxi;
}
void dfs(int i, int sum, int num)
{
	cnt[num]++;
	if (i > n)
	{
		ans = max(ans, sum);
		return ;
	}
	if (cnt[a[i].n1] + 1 <= m)
		dfs(i + 1, sum + a[i].maxi, a[i].n1);
	if (cnt[a[i].n2] + 1 <= m)
		dfs(i + 1, sum + a[i].mid, a[i].n2);
	if (cnt[a[i].n3] + 1 <= m)
		dfs(i + 1, sum + a[i].mini, a[i].n3);
}
void solve()
{
	cin >> n;
	bool f = 1, ff = 1;
	for (int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (y != 0 || z != 0) f = 0;
		if (x == y || x == z || y == z) ff = 0;
		int maxn = max(x, max(y, z));
		int minn = min(x, min(y, z));
		if (x != maxn && x != minn)  a[i].mid = x, a[i].n2 = 1;
		else if (y != maxn && y != minn)  a[i].mid = y, a[i].n2 = 2;
		else  a[i].mid = z, a[i].n2 = 3;
		a[i].diff = maxn - a[i].mid;
		a[i].maxi = maxn;
		if (x == maxn) a[i].n1 = 1;
		else if (y == maxn) a[i].n1 = 2;
		else a[i].n1 = 3;
		if (x == minn) a[i].n3 = 1;
		else if (y == minn) a[i].n3 = 2;
		else a[i].n3 = 3;
	}
	m = n / 2, ans = 0;
	int sum = 0;
	if (f)
	{
		sort(a + 1, a + n + 1, AwA);
		for (int i = 1; i <= m; i++)
			sum += a[i].maxi;
		cout << sum;
		return ;
	}
	if (ff)
	{
		sort(a + 1, a + n + 1, cmp);
		int m = n / 2, ans = 0;
		for (int i = 1; i <= 3; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[a[i].n1] + 1 <= m)
			{
				ans += a[i].maxi;
				cnt[a[i].n1] ++;
			}
			else
			{
				ans += a[i].mid;
				cnt[a[i].n2] ++;
			}
		}
		cout << ans << "\n";
		return ;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= 3; i++) cnt[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		sum += a[i].maxi;
		cnt[a[i].n1] ++;
	}
	if (m <= 15)
		dfs(m + 1, 0, 0);
	cout << ans + sum << "\n";
	return ;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}

