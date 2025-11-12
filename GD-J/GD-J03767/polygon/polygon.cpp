#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353, N = 5005;

int n, maxn = 0, cnt = 0;
int a[N];
void solve1()
{
	ll tot = 1;
	for (int i = 1; i <= n; i++) tot = tot * 2 % mod;
	ll less3 = n + 1 + n * (n - 1) / 2;
	tot = (tot - less3 + mod) % mod;
	cout << tot << '\n';
}

void dfs(int step, int sum, int maxl)
{
	if (step > n)
	{
		if (sum > maxl * 2) cnt++;
		return;
	}
	dfs(step + 1, sum + a[step], max(maxl, a[step]));
	dfs(step + 1, sum, maxl);
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (maxn == 1) solve1();
	else 
	{
		dfs(1, 0, 0);
		cout << cnt << '\n';
	}
	
	return 0;
}
