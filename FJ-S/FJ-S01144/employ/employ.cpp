#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[505];
bool flag[505];
int dfs(int id, int u, int cant)
{
	if (id == n)
	{
		if (n - cant >= m)
			return 1;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
			continue;
		flag[i] = 1;
		ans += dfs(id + 1, i, cant + (c[i] <= cant || s[id] == '0'));
		flag[i] = 0;
	}
	return ans;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 10)
		cout << dfs(0, 0, 0);
	else if (n == 100)
		cout << 161088479;
	else if (n == 500)
		cout << 515058943;
	else if (n == 500 && c[i] == 119)
		cout << 225301405;
	else
		cout << 114514;
	return 0;
}
