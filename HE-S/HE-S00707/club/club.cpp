#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int n, ans, maxn;
int an, bn, cn;
int a[N], b[N], c[N];

void dfs (int i)
{
	if (i > n) 
	{
		maxn = max(maxn, ans);
		return;
	}
	an++;
	if (an <= n / 2)
	{
		ans += a[i];
		dfs(i + 1);
		ans -= a[i];
	}
	an--;	
	bn++;
	if (bn <= n / 2)
	{
		ans += b[i];
		dfs(i + 1);
		ans -= b[i];
	}
	bn--;
	cn++;
	if (cn <= n / 2)
	{
		ans += c[i];
		dfs(i + 1);
		ans -= c[i];
	}
	cn--;
	return;
}
bool cmp (int a, int b) {return a > b;}
signed main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		bool is12 = 1, isc = 1;
		ans = maxn = an = bn = cn = 0;
		cin >> n; 
		if (n <= 10) is12 = 0, isc = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] || c[i]) is12 = 0;
		}
		if (!(is12 || isc)) 
		{
			dfs(1);
			cout << maxn << '\n';
		}
		else if (is12)
		{
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += a[i];
			cout << ans << '\n';
		}
		else
		{
			for (int i = 1; i <= n; i++)
				ans += max(a[i], max(b[i], c[i]));
			cout << ans << '\n';
		}
	}
	return 0;
}
