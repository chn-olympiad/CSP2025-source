#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e6 + 20;
int n, m, k, fa[N], ans;
struct node
{
	int u, v, w;
} p[N];
bool cmp(node &x, node &y)
{
	return x.w < y.w;
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1, x, y, z; i <= m; i++)
	{
		cin >> p[i].u >> p[i].v >> p[i].w;
	}
	sort(p + 1, p + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int x = find(p[i].u), y = find(p[i].v);
		if (x != y)
		{
			fa[y] = x;
			ans += p[i].w;
		}
	}
	cout << ans << "\n";
	return 0;
}
