#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int Mod = 998244353;
int n, m;
int c[505];
bool gg[505];
bool used[505];
int ks[505];
int anss = 0;
void dfs(int nw)
{
	if (nw == n + 1)
	{
		int cnt = 0;
		int tt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += (ks[i] > tt && gg[i]); 
			tt += !gg[i];
		}
		anss += (cnt >= m);
		anss %= Mod;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (used[i]) continue;
		ks[nw] = c[i];
		used[i] = 1;
		dfs(nw + 1);
		used[i] = 0;
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	bool isA = true;
	for (int i = 1; i <= n; i++)
	{
		char s;
		cin >> s;
		gg[i] = (s - '0');
		if (gg[i] == 0) isA = false;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (isA)
	{
		long long ans = 1;
		int tmp = n;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == 0) tmp--;
		}
		for (int i = 2; i <= n; i++)
		{
			ans = (ans * i) % Mod;
		}
		cout << ans << endl;
		return 0;
	}
	dfs(1);
	cout << anss % Mod << endl;
}
