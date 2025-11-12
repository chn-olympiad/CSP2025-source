#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 998244353;
ll n, a[5005], ans, temp, b[5005], c[5005][5005], sum, maxn = -1;
bool flag = true;
map<ll, ll> dp[5005];
void dfs(ll x)
{
	if (x == n + 1)
	{
		ll sum = 0, maxn = -1, cnt = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (b[i])
			{
				cnt++;
				sum += a[i];
				maxn = max(maxn, a[i]);
			}
		}
		if (sum > 2 * maxn && cnt >= 3)
		{
			ans = (ans + 1) % mod;
		}
		return;
	}
	b[x] = 0;
	dfs(x + 1);
	b[x] = 1;
	dfs(x + 1);
}
void init()
{
	for (ll i = 0; i <= n; i++)
	{
		c[i][0] = 1;
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1] % mod);
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	init();
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxn = max(maxn, a[i]);
		if (a[i] != 1)
		{
			flag = false;
		}
	}
	if (flag)
	{
		for (ll i = 3; i <= n; i++)
		{
			ans = (ans + c[n][i]) % mod;
		}
		cout << ans % mod << endl;
		return 0;
	}
	if (n <= 20)
	{
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	return 0;
}
/*
3
1 1 1

1
*/
/*
4
1 1 1 1

5
*/

/*
5
1 1 1 1 1

16
*/

/*
5
1 2 3 4 5

9
*/

/*
5
2 2 3 8 10

6
*/
