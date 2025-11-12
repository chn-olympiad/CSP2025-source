#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10100;
int n, fa[N], c[N], num[N];
int m, k, ans;
struct node{
	int u, v, w;
}a[N];
int get(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void unionn(int x, int y)
{
	x = get(x), y = get(y);
	if (x != y)
		fa[x] = y;
	return ;
}
bool cmp(node x, node y)
{
	return x.w < y.w;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[i].u = u, a[i].v = v, a[i].w = w;
	}
	for (int i = n + 1; i <= n + k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			a[++m].u = i, a[m].v = j, a[m].w = w + c[i];
		}
	}
	sort(a + 1, a + m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = a[i].u, v = a[i].v, w = a[i].w;
		if (get(u) != get(v))
		{
			if (u <= n && v <= n || (u <= n && fa[v] != v) || (v <= n && fa[u] != u))
				cnt++;
			if (u > n) num[u]++;
			if (v > n) num[v]++;
			ans += w;
			unionn(u, v);
			if (cnt == n - 1)
				break;
		}
	}
	for (int i = n + 1; i <= n + k + 1; i++)
		if (fa[i] != i)
			ans -= (num[i] - 1) * c[i];
	cout << ans;
	return 0;
}

