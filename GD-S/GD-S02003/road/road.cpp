#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4+7;

int n, m, k;

struct Node{int u, v;ll w;} e[N*200], con[11][N], E[N*201];

ll c[11];

int fa[N];

int find(int x)
{
	while(x != fa[x])
		x = fa[x] = fa[fa[x]];

	return x;
}

ll ans = 1e17;

int id;

ll cc;

bool vis[11];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for(int i(1); i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;

	for(int i(1); i <= k; ++i)
	{
		cin >> c[i];

		for(int j(1); j <= n; ++j)
			cin >> con[i][j].w, con[i][j].u = j, con[i][j].v = n + 1;
	}

	for(int i(1); i <= n+1; ++i)
		fa[i] = i;

	int cnt(0);

	ll res(0);

	sort(e+1, e+1+m, [&](Node x, Node y){return x.w < y.w;});

	for(int i(1); i <= m; ++i)
	{
		int u = e[i].u;
		int v = e[i].v;
		ll w = e[i].w;

		int x = find(u), y = find(v);
		if(x == y)continue;

		cnt++;
		fa[x] = y;
		res += w;

		if(cnt == n - 1)break;
	}

	if(cnt == n - 1)ans = res;


		for(int i(1); i <= k; ++i)
		{
			if(vis[i])continue;

			for(int j(1); j <= n+1; ++j)
				fa[j] = j;

			int nn = 0;
			res = c[i];
			cnt = 0;

			for(int j(1); j <= n; ++j)
				E[++nn] = e[j];

			for(int j(1); j <= n; ++j)
				E[++nn] = con[i][j];

			sort(E+1, E+1+nn, [&](Node x, Node y){return x.w < y.w;});

			for(int j(1); j <= nn; ++j)
			{
				int u = E[j].u;
				int v = E[j].v;
				ll w = E[j].w;

				int x = find(u);
				int y = find(v);

				if(x == y)continue;

				cnt++;
				fa[x] = y;
				res += w;

				if(cnt == n)continue;
			}

			if(res <= ans)ans = res;
		}
	cout << ans << '\n';

	return 0;
}
