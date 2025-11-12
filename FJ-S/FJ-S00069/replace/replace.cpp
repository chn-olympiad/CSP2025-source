#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 10057;
const int MAXN = 40005;
ll n, q, t1, t2, cnt;
ll b[MAXN];
int dp[MAXN][MOD];
ll fast_pow(int x, int y)
{
	ll res = 0;
	while (y)
	{
		if (y & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		y /= 2;
	}
	return res;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		string x, y;
		ll s1, s2;
		cin >> x >> y;
		int len = x.length();
		for (int j = 0; j < len; j ++)
		{
			s1 = (s1 + ((x[j] - 'a') * fast_pow(26, j) % MOD)) % MOD;
			s2 = (s2 + ((y[j] - 'a') * fast_pow(26, j) % MOD)) % MOD;
		}
		b[++cnt] = s2 - s1;
	}
	sort(b + 1, b + cnt + 1);
	while(q --)
	{
		string x, y;
		cin >> x >> y;
		int len = x.length();
		for (int j = 0; j < len; j ++)
		{
			t1 = (t1 + ((x[j] - 'a') * fast_pow(26, j) % MOD)) % MOD;
			t2 = (t2 + ((y[j] - 'a') * fast_pow(26, j) % MOD)) % MOD;
		}
		ll h = t2 - t1;
		dp[0][0] = 1;
		for (int i = 1; i <= cnt; i ++)
		{
			for (int j = h; j >= b[i]; j --)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]]) + 1;
		}
		cout << dp[cnt][h] << endl;
	}
	return 0;
}
