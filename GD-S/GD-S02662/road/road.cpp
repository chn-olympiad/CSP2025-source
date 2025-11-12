#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000010;
int read()
{
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return x;
}
struct edge
{
	int u, v, w;
}p[N], h[N];
int n, m, k, f[N], c[N];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int getfa(int x)
{
	if(f[x] == x)return x;
	return f[x] = getfa(f[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; i++)
	{
		p[i].u = read();
		p[i].v = read();
		p[i].w = read();
	}
	sort(p + 1, p + 1 + m, cmp);
	int mm = m;
	m = 0;
	for(int i = 1; i <= n; i++)f[i] = i;
	for(int i = 1; i <= mm; i++)
	{
		int u = getfa(p[i].u), v = getfa(p[i].v);
		if(u != v)
		{
			f[u] = v;
			p[++m] = p[i];
		}
	}
	int t = 0;
	for(int i = 1; i <= k; i++)
	{
		c[i] = read();
		for(int j = 1; j <= n; j++)
		{
			++t;
			h[t].u = i;
			h[t].v = j;
			h[t].w = read();
		}
	}
	sort(h + 1, h + 1 + t, cmp);
	ll ans = 1e18;
	for(int s = 0; s < (1 << k); s++)
	{
		for(int i = 1; i <= n + k; i++)f[i] = i;
		ll sum = 0;
		for(int i = 1; i <= k; i++)
			if(s&(1 << (i - 1)))
				sum += c[i];
		int pt = 1, ht = 1;
		while(pt <= m || ht <= t)
		{
			if(pt <= m && (ht > t || p[pt].w < h[ht].w))
			{
				int u = getfa(p[pt].u), v = getfa(p[pt].v);
				if(u != v)
				{
					f[u] = v;
					sum += p[pt].w;
				}
				pt++;
			}
			else
			{
				int u = getfa(h[ht].u + n), v = getfa(h[ht].v);
				if(u != v && h[ht].u <= k && (s&(1 << (h[ht].u - 1))))
				{
					f[u] = v;
					sum += h[ht].w;
				}
				ht++;
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
