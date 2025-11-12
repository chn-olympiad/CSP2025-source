#include <bits/stdc++.h>
#define int long long
using namespace std;

int x[5010], f[5010], n, ans;

int check()
{
	int sum = 0, maxn = 0, num = 0;
	for (int i = 1; i <= n; i++) if (f[i] == 1) sum += x[i], maxn = max(maxn, x[i]), num++;
	if (sum > 2 * maxn && num >= 3) return 1;
	else return 0;
}

void dfs(int k)
{
	if (k > n)
	{
		if (check()) ans++, ans %= 998244353;
		return ;
	}
	f[k] = 1;
	dfs(k + 1);
	f[k] = 0;
	dfs(k + 1);
} 

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	dfs(1);
	cout << ans;
	return 0;
}
