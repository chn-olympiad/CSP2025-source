#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int max(int a, int b) { return a > b ? a : b; }
struct node
{
	int a, b, c;
	bool operator < (const node &x)
	{
		return a < x.a;
	}
} p[100010];
void dfs(int i, int a, int b, int c, int x)
{
	if (i > n) { ans = max(ans, x); return ; }
	if (a + 1 <= n / 2) dfs(i + 1, a + 1, b, c, x + p[i].a);
	if (b + 1 <= n / 2) dfs(i + 1, a, b + 1, c, x + p[i].b);
	if (c + 1 <= n / 2) dfs(i + 1, a, b, c + 1, x + p[i].c);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 1, a, b, c; i <= n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			p[i] = {a, b, c};
		}
		sort(p + 1, p + 1 + n);
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
