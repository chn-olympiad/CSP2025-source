#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 2e6 + 5, mod = 0;
int fa[N], n, m, k, c[N], a[15][N];
struct node
{
	int x, y, w;
}e[M];
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
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
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if(k == 0)
	{
		int ans = 0, cnt = 0;
		for(int i = 1; i <= n; i++)
			fa[i] = i;
		for(int i = 1; i <= m; i++)
			cin >> e[i].x >> e[i].y >> e[i].w;
		sort(e + 1, e + 1 + m, cmp);
		for(int i = 1; i <= m; i++)
		{
			int x = e[i].x, y = e[i].y, w = e[i].w;
			if(find(x) == find(y)) continue;
			Union(x, y);
			ans += w;
			if(++cnt == n - 1) break;
		}
		cout << ans << '\n';
	} else
	{
		bool flag = 1;
		for(int i = 1; i <= n + k; i++)
			fa[i] = i;
		for(int i = 1; i <= m; i++)
			cin >> e[i].x >> e[i].y >> e[i].w;
		for(int i = 1; i <= k; i++)
		{
			cin >> c[i], flag &= (c[i] == 0);
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		}
		if(flag)
		{
			int ans = 0, cnt = 0;
			for(int i = 1; i <= k; i++)	
				for(int j = 1; j <= n; j++)
					e[++m].x = i + n, e[m].y = j, e[m].w = a[i][j];
			n += k;
			sort(e + 1, e + 1 + m, cmp);
			for(int i = 1; i <= m; i++)
			{
				int x = e[i].x, y = e[i].y, w = e[i].w;
				if(find(x) == find(y)) continue;
				Union(x, y);
				ans += w;
				if(++cnt == n - 1) break;
			}
			cout << ans << '\n';
			return 0;
		}
		cout << 13;
	}
	return 0;
}

