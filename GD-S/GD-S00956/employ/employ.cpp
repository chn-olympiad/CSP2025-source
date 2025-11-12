#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int a[15], c[15], f[15];
bool vis[15];
string s;

void dfs(int x)
{
	if (x == n + 1)
	{
		for (int i = 1; i <= n; i++) if (f[a[i] - 1] > c[i]) return ;
		ans++;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		a[x] = i;
		vis[i] = true;
		dfs(x + 1);
		vis[i] = false;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " "  + s;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + (s[i] == '0');
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
