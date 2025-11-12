#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e4 + 15, M = 1e6 + 5, K = 15;
int n, m, k, s, c[K], a[K][N];ll ans;
struct Edge{int u, v, w;}E[M];
bool cmp(Edge a, Edge b){return a.w < b.w;}

void read(int &x)
{
	x = 0;char c = getchar();
	while(c < 48 || 57 < c)c = getchar();
	while(48 <= c && c <= 57)x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}

int f[N];
int find(int x){return (x ^ f[x]) ? f[x] = find(f[x]) : x;}
vector <Edge> usE;
void kruskal1()
{
	for(int i = 1;i <= n;i++)f[i] = i;
	sort(E + 1, E + m + 1, cmp);
	for(int i = 1;i <= m;i++)
	{
		int u = find(E[i].u), v = find(E[i].v);
		if(u == v)continue;
		usE.push_back(E[i]), f[u] = v;
	}
}
void kruskal2()
{
	for(int i = 1;i <= n + k;i++)f[i] = i;
	sort(usE.begin(), usE.end(), cmp);
	for(Edge x : usE)
	{
		int u = find(x.u), v = find(x.v);
		if(u == v)continue;
		f[u] = v, ans += x.w;
	}
}

vector <Edge> tmp;
void solve()
{
	tmp = usE;ll res = 1e18;
	for(int i = 0;i < s;i++)
	{
		usE = tmp, ans = 0;
		for(int j = 1;j <= k;j++)
			if((i >> j - 1) & 1)
			{
				ans += c[j];
				for(int l = 1;l <= n;l++)
					usE.push_back((Edge){n + j, l, a[j][l]});
			}
		kruskal2(), res = min(res, ans);
	}
	printf("%lld\n", res);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	read(n), read(m), read(k), s = 1 << k;
	for(int i = 1;i <= m;i++)read(E[i].u), read(E[i].v), read(E[i].w);kruskal1();
	for(int i = 1;i <= k;i++)
	{
		read(c[i]);
		for(int j = 1;j <= n;j++)
			read(a[i][j]);
	}
	solve();
	return 0;
}
