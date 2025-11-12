#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
int n, m, k, fa[N], c[15], cnt[15], p[15], tot, l[15], mx;
long long ans;
struct road{
	int u, v, w;
}tp[M], rd[15][N];
void init()
{
	for(int i = 1, j = n+k; i <= j; i++)
		fa[i] = i;
}
int find(int i)
{
	if(i == fa[i])
		return i;
	return fa[i] = find(fa[i]);
}
bool cmp(road x, road y)
{
	return x.w < y.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &tp[i].u, &tp[i].v, &tp[i].w);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for(int j = 1, a; j <= n; j++)
		{
			scanf("%d", &a);
			rd[i][j] = {n+i, j, a};
		}
		sort(rd[i]+1, rd[i]+n+1, cmp);
	}
	init();
	sort(tp+1, tp+m+1, cmp);
	for(int i = 1; i <= m; i++)
	{
		int xx = find(tp[i].u), yy = find(tp[i].v), ww = tp[i].w;
		if(xx != yy)
		{
			rd[0][++cnt[0]] = tp[i];
			ans += ww;
			fa[xx] = yy;
			mx = max(mx, ww);
		}
	}
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
		{
			if(rd[i][j].w >= mx)
				break;
			cnt[i] = j;
		}
	int S = 1<<k;
	for(int i = 1; i < S; i++)
	{
		l[0] = 1;
		tot = 0;
		long long ww = 0;
		for(int j = 1; j <= k; j++)
		{
			int rr = 1<<j-1;
			if(i&rr)
			{
				p[++tot] = j, ww += c[j];
				l[tot] = 1;
			}
		}
		if(ww >= ans)
			continue;
		int pa = 0;
		init();
		while(1)
		{
			int cc = -1;
			for(int j = 0; j <= tot; j++)
				if(l[j] <= cnt[p[j]] && (cc == -1 || rd[p[j]][l[j]].w < rd[p[cc]][l[cc]].w))
					cc = j;
			if(cc == -1)
				break;
			int xx = find(rd[p[cc]][l[cc]].u), yy = find(rd[p[cc]][l[cc]].v);
			if(xx != yy)
			{
				ww += rd[p[cc]][l[cc]].w;
				if(ww >= ans)
					break;
				fa[xx] = yy;
				pa++;
				if(pa == n+tot)
					break;
			}
			l[cc]++;
		}
		if(ww < ans)
			ans = ww;
	}
	printf("%lld", ans);
	return 0;
}
