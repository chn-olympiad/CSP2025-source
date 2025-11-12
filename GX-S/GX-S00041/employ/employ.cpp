#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL P = 998244353;
const LL N = 514;
bool s[N], vis[N];
LL c[N];
LL n, m, cnt, ans, mx;
char ch;
void dfs(LL i, LL j, LL k)
{
	if (i == n + 1 && k >= m) ans = (ans + 1) % P;
	if (j >= mx) return;
	for (LL nxt = 1; nxt <= n; nxt++)
	{
		if (!vis[nxt])
		{
			vis[nxt] = 1;
			if (j < c[nxt] && s[i]) dfs(i + 1, j, k + 1);
			else dfs(i + 1, j + 1, k);
			vis[nxt] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (LL i = 1; i <= n; i++)
		cin >> ch, cnt += (s[i] = ch - '0');
	for (LL i = 1; i <= n; i++) cin >> c[i], mx = max(mx, c[i]);
	if (cnt == n)
	{
		ans = 1;
		for (LL i = 2; i <= n; i++) ans = ans * i % P;
	}
	else dfs(1, 0, 0);
	cout << ans;
	return 0;
}