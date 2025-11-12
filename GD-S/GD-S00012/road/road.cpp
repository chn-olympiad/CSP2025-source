#include <bits/stdc++.h>
using namespace std;
long long CNT(long long gg)
{
	long long cnt = 0;
	while(gg > 0)
		gg -= (gg & -gg), cnt++;
	return cnt;
}
long long read()
{
	long long wbh = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		wbh = (wbh << 3) + (wbh << 1) + ch - '0';
		ch = getchar();
	}
	return wbh;
}
const long long N = 10010, M = 1000006, K = 15;
long long n, m, k, f[N + K], l, ans, c[K], g[K], op, y, ck, fm[K];
struct tt
{
	long long u, v, w;
	friend bool operator < (const tt a, const tt b)
	{
		return a.w < b.w;
	}
}e[M], t[K][N + K];
long long find(long long x)
{
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
long long mini_tree(long long x, long cc)
{
	long long cnt = 0, p = 0, minn = 0;
	for (long long i = 1; i <= n + k; i++)
		f[i] = i;
	for (long long i = 0; i <= k; i++)	
		g[i] = 1;
	for (long long i = 1, j = 1; i <= x; i <<= 1, j++)
		if (i & x)
			cnt += c[j];
	for (long long i = 1; i < n + cc; i++)
	{
		while(g[0] <= m && find(e[g[0]].u) == find(e[g[0]].v))
			g[0]++;
		if (g[0] <= m)
			minn = e[g[0]].w;
		else
			minn = 1145141919810114514ll;
		p = 0;
		for (long long j = 1; j <= k; j++)
		{
			if ((1 << (j - 1)) & x)
			{
				while(g[j] <= n && find(t[j][g[j]].u) == find(t[j][g[j]].v))
					g[j]++;
				if (g[j] > n)
					continue;
				if (t[j][g[j]].w < minn)
				{
					minn = t[j][g[j]].w;
					p = j;
				}
			}
		}
		if (minn == 1145141919810114514ll)
			return 1145141919810114514ll;
		cnt += minn;
		if (p)
			f[find(t[p][g[p]].u)] = find(t[p][g[p]].v);
		else
			f[find(e[g[p]].u)] = find(e[g[p]].v);
		g[p]++;
	}
	return cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	for (long long i = 1; i <= m; i++)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + 1 + m);
	for (long long i = 1; i <= k; i++)
	{
		c[i] = read();
		for (long long j = 1; j <= n; j++)
		{
			t[i][j].u = i + n;
			t[i][j].v = j;
			t[i][j].w = read();
		}
		sort(t[i] + 1, t[i] + 1 + n);
	}
	for (long long i = 1; i <= k; i++)
		fm[i] = mini_tree(1 << (i - 1), 1);
	for (long long i = 1; i <= k; i++)
	{
		for (long long j = 1; j < i; j++)
			if (fm[j] > fm[j + 1])
			{
				for (long long s = 1; s <= n; s++)
				{
					swap(t[j][s].u, t[j + 1][s].u);
					swap(t[j][s].v, t[j + 1][s].v);
					swap(t[j][s].w, t[j + 1][s].w);
				}
				swap(c[j], c[j + 1]);
				swap(fm[j], fm[j + 1]);
			}
	}
	ans = mini_tree(0, 0);
	l = 0, ck = 0;
	for (long long i = 1, j = 1; i <= k; i++, j <<= 1)
	{
		op = mini_tree(j | l, ck + 1);
		if (op < ans)
			l |= j, ans = op, ck++;
	}
	printf("%lld", ans);
}
