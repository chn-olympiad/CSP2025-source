#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e4 + 5;
int n, m, k;
int fa[N] = {};
bool st[N];

struct donk {
	int r, w, c;
};

vector<donk> g;

bool cmp(donk x, donk y)
{
	return x.c < y.c;
}

int find(int x)
{
	if(x != fa[x])
	{
		fa[x] = find(fa[x]);
		return fa[x];
	}
	return fa[x];
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v, ll;
		cin >> u >> v >> ll;
		g.push_back({u, v, ll});
	}
	for(int i = 1; i <= k; i++)
	{
		int cc;
		cin >> cc;
		for(int j = 1; j <= n; j++)
		{
			int ww;
			cin >> ww;
			g.push_back({n + i, j, ww});
		}
	}
	sort(g.begin(), g.end(), cmp);
	int cnt = 0;
	int all_nums = 0;
	int add_cgrs = 0;
	for(int i = 0; i < g.size(); i++)
	{
		if(find(g[i].r) == find(g[i].w)) continue;
		fa[g[i].r] = fa[g[i].w];
		cnt += g[i].c;
		all_nums++;
		if(g[i].r > n && st[g[i].r] == false)
		{
			add_cgrs++;
			st[g[i].r] = true;
		}
		if(add_cgrs + n == all_nums + 1)
		{
			cout << cnt << endl;
			return 0;
		}
	}
}
