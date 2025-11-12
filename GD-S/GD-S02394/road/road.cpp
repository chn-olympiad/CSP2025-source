#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 6, M = 1e6 + 6, K = 16;
typedef long long LL;
struct edge 
{
	int type, u, v; 
	LL w;
} 
e[M], t[M + N * K];
int n, m, k, father[N], fstcon[K], cntcon[K];
LL c[K], a[K][N], ans = 9e18, fcw[K];
bool city[K];
int find(int u)
{
	return (u == father[u])? u:father[u] = find(father[u]);
}
void merge(int u, int v)
{
	int fu = father[u], fv = father[v];
	father[fu] = fv;
}
bool cmp(edge e1, edge e2) {return e1.w < e2.w;}
inline unsigned int read()
{
	unsigned int res = 0; char c = '0';
	while ('0' <= c)
	{
		res = res * 10 + c - '0';
		c = getchar(); 
	} 
	return res;
}
LL Solve()
{
	LL res = 0;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++) t[i] = {e[i].type, e[i].u, e[i].v, e[i].w};
	int cur = m; 
	for (int i = 1; i <= k; i++)
	{
		fstcon[i] = 0;
		cntcon[i] = 0;
		fcw[i] = 0;
		if (!city[i]) continue;
		res += c[i];
		for (int j = 1; j <= n; j++)
			t[++cur] = {2, j, i, a[i][j]};
	}
	sort(t + 1, t + cur + 1, cmp);
	for (int i = 1; i <= cur; i++)
	{
		int type = t[i].type, u = t[i].u, v = t[i].v;
		LL w = t[i].w;
		if (type == 1)
		{
			if (find(u) == find(v)) continue;
			merge(u, v);
			res += w;
		}
		else
		{
			if (!fstcon[v]) 
			{
				fstcon[v] = u; 
				res += w;
				cntcon[v] = 1; 
				fcw[v] = w;
			}
			else
			{
				if (find((fstcon[v])) == find(u)) continue;
				merge(u, fstcon[v]);
				res += w;
				cntcon[v]++;
			}
		}
	}
	for (int i = 1; i <= k; i++)
		if (cntcon[i] == 1) res -= fcw[i];
	return res; 
}
void GenerateCity(int x)
{
	if (x > k) 
	{
		ans = min(ans, Solve());
		return;
	}
	city[x] = 1; GenerateCity(x + 1);
	city[x] = 0; GenerateCity(x + 1);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k); e[0].u = read();
	for (int i = 1; i <= m; i++)
		e[i].u = read(), e[i].v = read(), e[i].w = read(), e[i].type = 1;
	bool flagA = 1;
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]); if (c[i] != 0) flagA = false;
		for (int j = 1; j <= n; j++) 
		{
			scanf("%lld", &a[i][j]);
			if (a[i][j] != 0) flagA = false;
		}
	}
	if (flagA) {printf("0"); return 0;}
	GenerateCity(1);
	printf("%lld\n", ans);
	return 0;
}
