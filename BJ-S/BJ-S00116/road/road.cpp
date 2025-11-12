#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, newn, newm;
struct node
{
	int u, v, w;
	bool friend operator < (node a, node b)
	{
		return a.w <= b.w;
	}
}edge[2000005], Edge[2000005], EDGE[2000005];
int c[15], W[15][200005], fa[2000005];
bool used[2000005];
int fr(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = fr(fa[x]);
}
int kruskal1()
{
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= n; i ++) fa[i] = i;
	int cnt = 0, ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;;
		int fu = fr(u), fv = fr(v);
		if(fu == fv) continue;
		used[i] = 1;
		fa[fu] = fv;
		cnt ++;
		ans += w;
		if(cnt == n - 1) return ans;
	}
}
int kruskal2()
{
	//cout << newm << endl;
	sort(Edge + 1, Edge + newm + 1);
	for(int i = 1; i <= newn; i ++) fa[i] = i;
	int cnt = 0, ans = 0;
	for(int i = 1; i <= newm; i ++)
	{
		int u = Edge[i].u, v = Edge[i].v, w = Edge[i].w;;
		int fu = fr(u), fv = fr(v);
		if(fu == fv) continue;
		fa[fu] = fv;
		cnt ++;
		ans += w;
		if(cnt == newn - 1) return ans;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for(int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j ++)
		{
			cin >> W[i][j];
		}
	}
	int ans = kruskal1();
	int Cnt = 0;
	for(int i = 1; i <= m; i ++)
	{
		if(used[i])
		{
			Edge[++ Cnt] = edge[i];
			EDGE[Cnt] = edge[i];
		}
	}
	for(int u = 0; u < (1 << k); u ++)
	{
		int tmp = 0;
		newn = n;
		newm = Cnt;
		for(int i = 1; i <= k; i ++)
		{
			if((u >> (i - 1)) & 1)
			{
				newn ++;
				tmp += c[i];
				for(int j = 1; j <= n; j ++)
				{
					Edge[++ newm] = node{newn, j, W[i][j]};
				}
			}
		}
		//for(int j = 1; j <= newm; j ++)
		//{
		//	//cout << Edge[j].u << ' ' << Edge[j].v << ' ' << Edge[j].w << endl;
		//}
		//cout << tmp << endl << kruskal2() << endl;
		ans = min(ans, tmp + kruskal2());
		for(int i = 1; i <= Cnt; i ++)
		{
			Edge[i] = EDGE[i];
		}
		//cout << u << endl;
	}
	cout << ans;
	return 0;
}
