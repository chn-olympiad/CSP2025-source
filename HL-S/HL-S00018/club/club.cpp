#include <cstdio>
using namespace std;
int n, a[100001][4], ans;
void dfs(int t, int u, int v, int w, int x, int y, int z)
{
	if (z == n + 1)
	{
		if ((t + u + v) >= ans)
		{
			ans = t + u + v;
		}
		return;
	}
	if (w + 1 <= n / 2)
	{
		dfs(t + a[z][1], u, v, w + 1, x, y, z + 1);
	}
	if (x + 1 <= n / 2)
	{
		dfs(t, u + a[z][2], v, w, x + 1, y, z + 1);
	}
	if (y + 1 <= n / 2)
	{
		dfs(t, u, v + a[z][3], w, x, y + 1, z + 1);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int l;
	scanf("%d", &l);
	for (int i = 1; i <= l; i ++)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= 3; j ++)
			{
				scanf("%d", &(a[i][j]));
			}
		}
		dfs(0, 0, 0, 0, 0, 0, 1);
		printf("%d\n", ans);
	}
	return 0;
}