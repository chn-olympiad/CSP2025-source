#include <bits/stdc++.h>
using namespace std;
const int N = 20, mod = 998244353;
int n, m, c[N], st[N], res;
char s[N];
void dfs(int u, int X)
{
	if (u == n)
	{
		res += ((n - X) >= m);
		return;
	}
	if (n - X < m)return;
	for (int i = 0; i < n; i ++)
	{
		if (!st[i])
		{
			st[i] = 1;
			dfs(u + 1, X + (s[u] == '0' || X >= c[i]));
			st[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; i ++)scanf("%d", &c[i]);
	dfs(0, 0);
	printf("%d", res);
	return 0;
}