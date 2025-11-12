#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rdi(int& x)
{
	char c;
	while((c = getchar_unlocked()) > '9' || c < '0');
	x = c - '0';
	while((c = getchar_unlocked()) >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
	}
}
int n, m, k, c[15], a[11][10005];
struct Edge {
	int u, v, w;
	void in()
	{
		rdi(u); rdi(v); rdi(w);
	}
} e[1100005];
bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}
struct DSU {
	int fa[10015], sz[10015], cnt;
	DSU() {}
	DSU(int n)
	{
		cnt = n;
		for(int i=1;i<=n;i++)
		{
			fa[i] = i, sz[i] = 1;
		}
	}
	int fnd(int x)
	{
		return fa[x] == x ? x : fa[x] = fnd(fa[x]);
	}
	bool uni(int x, int y)
	{
		if((x = fnd(x)) == (y = fnd(y)))
		{
			return 0;
		}
		cnt--;
		if(sz[x] > sz[y])
		{
			swap(x, y);
		}
		fa[x] = y, sz[y] += sz[x];
		return 1;
	}
};
int necur = 0;
Edge ne[110005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rdi(n); rdi(m); rdi(k);
	for(int i=1;i<=m;i++)
	{
		e[i].in();
	}
	int ecur = m;
	for(int i=1;i<=k;i++)
	{
		rdi(c[i]);
		for(int j=1;j<=n;j++)
		{
			rdi(a[i][j]);
			e[++ecur] = {n + i, j, a[i][j]};
		}
	}
	sort(e + 1, e + ecur + 1, cmp);
	DSU dsu(n);
	for(int i=1;dsu.cnt>1&&i<=ecur;i++)
	{
		if(e[i].u > n)
		{
			ne[++necur] = e[i];
		}
		else
		{
			if(dsu.uni(e[i].u, e[i].v))
			{
				ne[++necur] = e[i];
			}
		}
	}
	ll ans = 1e18;
	for(int i=0;i<(1<<k);i++)
	{
		ll sum = 0;
		int cnt = 1;
		for(int j=0;j<k;j++)
		{
			if((i >> j) & 1)
			{
				sum += c[j + 1];
			}
			else
			{
				cnt++;
			}
		}
		DSU dsu(n + k);
		for(int j=1;dsu.cnt>cnt&&j<=necur;j++)
		{
			if(ne[j].u > n)
			{
				if(((i >> (ne[j].u - n - 1)) & 1) && dsu.uni(ne[j].u, ne[j].v))
				{
					sum += ne[j].w;
				}
			}
			else
			{
				if(dsu.uni(ne[j].u, ne[j].v))
				{
					sum += ne[j].w;
				}
			}
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
