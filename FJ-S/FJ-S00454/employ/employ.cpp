#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505;
int c[N], s[N];
bool b[N];
int n, m, ans;
void dfs(const int& d = 1, const int& sum = 0)
{
	if (d == n + 1)
	{
		if (sum >= m)
			++ ans;
		return;
	}
	for (int i = 1; i <= n; i ++)
		if (!b[i])
		{
			b[i] = true;
			dfs(d + 1, sum + ((c[i] > d - 1 - sum) && s[i] ? 1 : 0));
			b[i] = false;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	string ss;
	cin >> ss;
	ss = " " + ss;
	for (int i = 1; i <= n; i ++)
	{
//		cin >> s[i]/*, s[i] += s[i - 1]*/;
		s[i] = (ss[i] == '1');
	}
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	dfs();
	cout << ans << '\n';
	return 0;
}
