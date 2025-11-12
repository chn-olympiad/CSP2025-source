#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 998244353;
ll n, ans;
int a[5005];
int s[5005];

int qpow(int x, int y)
{
	ll ret = 1;
	while (y)
	{
		if (y & 1) (ret *= x) %= P;
		(x *= x) %= P;
		y >>= 1;
	}
	return ret % P;
}

int dfs(int dep, int ed, int ch, ll sum)
{
	if (dep >= ed)
	{
		if (ch < 2) return 0;
		if (sum > a[ed]) return 1;
	}
	ll ret = 0;
	if (sum + s[ed - 1] - s[dep] > a[ed]) ((ret += dfs(dep + 1, ed, ch, sum)) %= P);
	if (sum + s[ed - 1] - s[dep - 1] > a[ed]) ((ret += dfs(dep + 1, ed, ch + 1, sum + a[dep])) %= P);
	return ret;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n;
	int t = 1;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], t = min(t, (int)(a[i] == 1));
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	if (n == 3)
	{
		if (a[1] + a[2] > a[3]) cout << "1\n";
		else cout << "0\n";
		return 0;
	}
	if (t)
	{
		cout << (qpow(2, n) - n - n * (n - 1) / 2 % P) % P << '\n';
		return 0;
	}
	int ans = 0;
	for (int i = 3; i <= n; i++)
		(ans += dfs(1, i, 0, 0)) %= P;
	cout << ans << '\n';
    return 0;
}