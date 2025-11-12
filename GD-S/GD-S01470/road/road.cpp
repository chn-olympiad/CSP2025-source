#include <bits/stdc++.h>
#define endl '\n'
#define f_c first
#define idx second
using namespace std;
typedef long long LL;
const int MAXN = 10005, MAXM = 1000005;
struct edge { LL u, v, w; } e[MAXM * 2 + MAXN * 20];
//LL r[15][MAXN];
LL fa[MAXN];
int n, m, k;
LL ans = 0;
bool used[15], vis[MAXN]; 
map<pair<LL, LL>, pair<LL, LL> > fix_cost;

LL find(LL x)
{
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void kruskal()
{
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (cnt == n - 1) return ;
		
		LL u = e[i].u, v = e[i].v, w = e[i].w;
		LL fu = find(u), fv = find(v);
		
//		cout << u << ' ' << v << ' ' << w << ' ';
		
		if (fu != fv)
		{
			fa[fu] = fv;
			cnt++;

			auto now = fix_cost[{u, v}];
			if (now.idx && !used[now.idx]) 
				w -= now.f_c, used[now.idx] = true;
			
//			cout << w << endl;
			
			ans += w;
			
//			cout << '*' << now.f_c << ' ' << ans;
		}
		
//		cout << endl;
	}
	
	return ;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	
	bool is = true;
	
	for (int i = 1; i <= k; i++)
	{
		LL f_c; cin >> f_c; if (f_c) is = false;
		for (int j = 1; j <= n; j++)
		{
			LL w; cin >> w; if (w) is = false;
			e[++m] = {i, j, w + f_c};
//			e[++m] = {j, i, w + f_c};
			fix_cost[{i, j}] = {f_c, i};
//			fix_cost[{j, i}] = {f_c, i};
		}
	}	
	
	if (is) { cout << 0 << endl; return 0; }
	
	sort(e + 1, e + m + 1, [](edge x, edge y){ return x.w < y.w; });
	
	kruskal();
	
	cout << ans << endl;

	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

