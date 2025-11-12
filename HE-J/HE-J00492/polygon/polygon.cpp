#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int Mod = 998244353;
int n;
int a[5005];
ll ans = 0;
void dfs(int nw, int sel, int mx, int sm)
{
	if (nw == n + 1)
	{
		if (sel >= 3)
		{
			ans += (sm > 2 * mx);
		}
		return;
	}
	dfs(nw + 1, sel, mx, sm);
	dfs(nw + 1, sel + 1, max(mx, a[nw]), sm + a[nw]);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans % Mod << endl;
	return 0;
}
