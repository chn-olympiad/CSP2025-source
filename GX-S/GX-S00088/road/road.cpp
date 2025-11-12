#include <bits/stdc++.h>
#define town(s, k) ((k == 0) || ((s) & (1 << ((k) - 1))) != 0)
#define ll long long
using namespace std;
ll read()
{
	char c = ' ';
	ll res = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	return res;
}
const int N = 1e4 + 105, M = 1e6 + 5, K = 13;
int n, m, k, m2, p[N];
int ff(int i) {return p[i] == i ? i : p[i] = ff(p[i]);}
struct edge
{
	int u, v, i;
	ll w;
}e[M], e2[M];
bool cmp(edge e1, edge e2) {return e1.w < e2.w;}
ll ans, c[K], a[K][N];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	//printf("%d %d %d\n", n, m, k);
	for(int x = 1; x <= m; x++) e[x].u = read(), e[x].v = read(), e[x].w = read(), e[x].i = 0;
	sort(e + 1, e + 1 + m, cmp);
	for(int x = 1; x <= n + k; x++) p[x] = x;
	for(int x = 1; x <= m; x++)
	{
		if(ff(e[x].u) == ff(e[x].v)) continue;
		p[ff(e[x].u)] = p[e[x].v];
		e2[++m2] = e[x];
		ans += e[x].w;
	}
	//printf("ans = %lld\n", ans);
	for(int x = 1; x <= k; x++)
	{
		c[x] = read();
		for(int y = 1; y <= n; y++)
		{
			a[x][y] = read();
			e2[++m2].i = x;
			e2[m2].u = x + n;
			e2[m2].v = y;
			e2[m2].w = a[x][y];
		}
	}
	sort(e2 + 1, e2 + 1 + m2, cmp);
	//printf("m2 = %d\n", m2);
	//for(int x = 1; x <= m2; x++) printf("edge %d: %d<-->%d %lld    town %d\n", x, e2[x].u, e2[x].v, e2[x].w, e2[x].i);
	for(int s = 0; s < (1 << k); s++)
	{
		ll res = 0;
		for(int x = 1; x <= k; x++) if(town(s, x)) res += c[x];
		//printf("s = %d, res = %lld\n", s, res);
		//for(int x = 1; x <= k; x++) if(town(s, x)) printf("%d:%lld ", x, c[x]);
		//printf("\n");
		for(int x = 1; x <= n + k; x++) p[x] = x;
		for(int x = 1; x <= m2; x++)
		{
			if(!town(s, e2[x].i) || ff(e2[x].u) == ff(e2[x].v)) continue;
			p[ff(e2[x].u)] = p[e2[x].v];
			res += e2[x].w;
		}
		//printf("s = %d, res = %lld\n", s, res);
		ans = min(ans, res);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
