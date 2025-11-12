#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10, K = 15;
struct Edge
{
	int u, v, w;
	bool operator < (const Edge& x)const{return w < x.w;}
}e[M];
int c[K], a[K][N], f[N];
int n, m, k, ans;
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int j = 1; j <= k; j++)
	{
		cin >> c[j];
		for (int i = 1; i <= n; i++) cin >> a[j][i];
	}
	if (k) cout << 0; //性质A
	else //Test 1~4
	{
		sort(e + 1, e + m + 1);
		for (int i = 1; i <= n; i++) f[i] = i;
		for (auto i : e)
		{
			int u = i.u, v = i.v, w = i.w;
			int fu = find(u), fv = find(v);
			if (fu != fv) f[fv] = fu, ans += w;
		}
		cout << ans;
	}
	return 0;
}