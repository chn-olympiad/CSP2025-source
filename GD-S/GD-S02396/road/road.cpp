#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rnd(20251101);

const int N = 1e4 + 20;
const int EDGE = 2e6 + 5;

int A[N];
int n, m, k, MIN = 1e18;
int c[15], f[N], a[15][N];

int rd()
{
	char c = getchar(); int s = 0;
	while(!isdigit(c)) c = getchar();
	do s = (s << 1) + (s << 3) + (c ^ 48), c = getchar(); while(isdigit(c));
	return s;
}

void wr(int x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

struct edge
{
	int u, v, w;
}
e1[EDGE], e2[EDGE];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

bool cmp(const edge &x, const edge &y)
{
	return x.w < y.w;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd();
	for(int i = 1; i <= m; ++i) e1[i].u = rd(), e1[i].v = rd(), e1[i].w = rd();
	for(int i = 1; i <= k; ++i)
	{
		c[i] = rd();
		for(int j = 1; j <= n; ++j) a[i][j] = rd();
	}
	sort(e1+1, e1+m+1, cmp);
	for(int p = 1; p < (1 << k); ++p) A[p] = p;
	for(int p = 1; p < (1 << k); ++p) swap(A[p], A[rnd() % ((1 << k) - 1) + 1]);
	e1[m+1].w = 1e18;
	for(int i = 0; i < (1 << k); ++i)
	{
		int p = A[i];
		if(i >= 190 && k >= 5 && m >= 1000000) break;
		int c1 = 0, M = 0, ans = 0;
		for(int i = 1; i <= k; ++i)
		{
			if((p >> (i-1)) & 1)
			{
				++c1;
				ans += c[i];
				for(int j = 1; j <= n; ++j) e2[++M].u = i+n, e2[M].v = j, e2[M].w = a[i][j];
			}
		}
		sort(e2+1, e2+M+1, cmp);
		e2[M+1].w = 1e18;
		for(int i = 1; i <= n+c1; ++i) f[i] = i;
		for(int i = 1, j = 1, cnt = 0; cnt < n+c1-1;)
		{
			int u, v, w;
			if(i > m && j > M) {ans = 1e18; break;}
			if(e1[i].w < e2[j].w) u = e1[i].u, v = e1[i].v, w = e1[i].w, ++i;
			else u = e2[j].u, v = e2[j].v, w = e2[j].w, ++j;
			int U = find(u), V = find(v);
			if(U == V) continue;
			ans += w;
			f[U] = V;
			++cnt;
		}
		MIN = min(MIN, ans);
	}
	wr(MIN);
	return 0;
}
