#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e3 + 5;

int n, m, ans;
int s[MAXN], c[MAXN], p[MAXN];
bool vis[MAXN];

void Dfs(int pos, int cm)
{
	if (n - cm < m)
		return;
	if (pos > n)
	{
		if (n - cm >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			p[pos] = i;
			vis[i] = true;
			if (!s[pos] || cm >= c[i])
				Dfs(pos + 1, cm + 1);
			else
				Dfs(pos + 1, cm);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%1d", s + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i);
	Dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
