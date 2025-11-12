#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll n, a[5005], ans;

void dfs(int step, ll sum, ll maxn)
{
	if (step > n)
	{
		if (sum > 2 * maxn)
			ans = (ans + 1) % mod;
		return;
	}
	dfs(step + 1, sum + a[step], max(maxn, a[step]));
	dfs(step + 1, sum, maxn);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1) flag = false;
	}
	if (flag)
	{
		ll mul = 1;
		for (int i = 1; i <= n; i++)
			mul = (mul * 2) % mod;
		mul -= 1;
		mul -= n;
		mul -= n * (n - 1) / 2;
		mul %= mod;
		if (mul < 0) mul += mod;
		cout << mul << endl;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
