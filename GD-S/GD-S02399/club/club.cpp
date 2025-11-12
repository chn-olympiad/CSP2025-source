#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int T, n;
struct P
{
	int a[3], id;
};
P a[100005];
int f[205][205][205];
void solve()
{
	bool flag = true, flag2 = true;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2];
		if (a[i].a[1] != 0 || a[i].a[2] != 0)
			flag = false;
		if (a[i].a[2] != 0)
			flag2 = false;
		a[i].id = i;
	}
	if (flag)
	{
		sort(a + 1, a + n + 1, [](P A, P B){
			return A.a[0] > B.a[0];
		});
		int sum = 0;
		for (int i = 1, to = n / 2; i <= to; i++)
			sum += a[i].a[0];
		cout << sum << '\n';
		return;
	}
	if (flag2)
	{
		sort(a + 1, a + n + 1, [](P A, P B){
			return A.a[0] > B.a[0];
		});
		int sum = 0, sum2 = 0;
		for (int i = 1; i <= n; i++)
			sum2 += a[i].a[1];
		int ans = sum2;
		for (int i = 1; i <= n; i++)
		{
			sum += a[i].a[0];
			sum2 -= a[i].a[1];
			ans = max(sum + sum2, ans);
		}
		sort(a + 1, a + n + 1, [](P A, P B){
			return A.a[1] > B.a[1];
		});
		sum = 0, sum2 = 0;
		for (int i = 1; i <= n; i++)
			sum += a[i].a[0];
		ans = max(sum, ans);
		for (int i = 1; i <= n; i++)
		{
			sum -= a[i].a[0];
			sum2 += a[i].a[1];
			ans = max(sum + sum2, ans);
		}
	}
	if (n <= 200)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0, to2 = i - j; k <= to2; k++)
				{
					int l = i - j - k;
					if (j > n / 2 || k > n / 2 || l > n / 2)
						continue;
					if (j > 0)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i].a[0]);
					if (k > 0)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i].a[1]);
					if (l > 0)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i].a[2]);
	//				cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << f[i][j][k] << '\n';
				}
			}
		}
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
				ans = max(ans, f[n][j][k]);
		cout << ans << '\n';
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= n; k++)
					f[i][j][k] = 0;
	}
	
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
		solve();
}
