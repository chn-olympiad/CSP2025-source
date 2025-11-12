#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4 + 5;
const int M = 1e6 + 5;

int fa[N];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	fa[x] = y;
}

struct Edge
{
	int u, v, w;
	void read()
	{
		cin >> u >> v >> w;
	}
}e[M];

bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		e[i].read();
	
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	
	sort(e + 1, e + m + 1, cmp);
	
	for(int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v))
		{
			merge(u, v);
			ans += w;
		}
	}
	
	cout << ans;
	
	return 0;
}

