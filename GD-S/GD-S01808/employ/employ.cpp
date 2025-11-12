#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, c[505], m, res[505], p, ans;
bool vis[505], flag = 1;
char s[505];
void dfs(int step)
{
	if (step == n + 1)
	{
		int num = 0, cnt = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (s[i] == '0')
			{
				num ++;
				continue;
			}
			if (num >= c[res[i]])
				num ++;
			else
				cnt ++;
		}
		if (cnt >= m)
			ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (vis[i])
			continue;
		vis[i] = 1;
		res[step] = i;
		dfs(step + 1);
		vis[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		if (s[i] == '0')
			flag = 0;
	}
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	if (flag)
	{
		ans = 1;
		for (int i = n; i >= 1; i --)
			ans = (ans * i) % mod;
	}
	else
		dfs(1);
	cout << ans;
	return 0;
}
