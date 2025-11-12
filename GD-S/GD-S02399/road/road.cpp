#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n, m, k;
int f[10005];
struct edge
{
	int u, v, w;
};
edge e[1000005];
int c[15], a[15][10005];
int tag[15][10005];
int cnt;
int ans;
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[++cnt] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	sort(e + 1, e + cnt + 1, [](edge A, edge B){
		return A.w < B.w;
	});
	for (int i = 1, cnt2 = 0, to = n - 1; i <= cnt && cnt2 < to; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int id = 0;
		for (int j = 1; j <= k; j++)
		{
			if (w > (tag[j][u] == 0 ? a[j][u] : 0) + (tag[j][v] == 0 ? a[j][v] : 0))
			{
				id = j;
				w = (tag[j][u] == 0 ? a[j][u] : 0) + (tag[j][v] == 0 ? a[j][v] : 0);
			}
		}
		tag[id][u] = tag[id][v] = 1;
		int fu = find(u), fv = find(v);
		if (fu != fv)
		{
			f[fu] = fv, cnt2++;
			ans += w;
		}
	}
	cout << ans;
}
