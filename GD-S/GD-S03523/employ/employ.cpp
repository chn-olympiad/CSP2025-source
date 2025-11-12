#include <bits/stdc++.h>
using namespace std;
const int N = 200480, P = 998244353;
int n, m;
long long ans = 0;
char s[N];
int a[N];
bool b[N];
void Dfs(int x, int v)
{
	if (x == n && v >= m)
	{
		++ans;
		if (ans >= P)
			ans -= P;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!b[i])
		{
			b[i] = true;
			if (s[x] == '0' || x - v >= a[i])
				Dfs(x + 1, v);
			else
				Dfs(x + 1, v + 1);
			b[i] = false;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	Dfs(0, 0);
	cout << ans;
	return 0;
}
