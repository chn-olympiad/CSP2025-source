#include <iostream> 
#include <algorithm>

using namespace std;

namespace Fast_read
{
	template <typename T>
	inline void read(T &w) ;
	template <typename T>
	inline void print(T ans) ;
};
using namespace Fast_read;

int n, m1, m2, p[10020];
long long v[15][10010], ans = 1e18, res = 0;

struct EDGE
{
	int a, b;
	long long c;
	bool operator< (const EDGE &t)const
	{
		return c < t.c;
	}
}edge[1000010], Edge[1100010];
int cnt = 0;

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve1()
{
	for (register int i = 1, a, b, c; i <= m1; ++ i)
	{
		read(a), read(b), read(c);
		edge[i] = {a, b, c};
	}
	for (register int i = 1; i <= m2; ++ i)
	{
		read(v[i][0]);
		for (register int j = 1; j <= n; ++ j)
		{
			read(v[i][j]);
		}
	}
	for (register int i = 1; i <= n; ++ i) p[i] = i;
	sort (edge + 1, edge + m1 + 1), cnt = 0;
	for (register int i = 1, sum = 0; i <= m1; ++ i)
	{
		int a = edge[i].a, b = edge[i].b, c = edge[i].c;
		a = find(a), b = find(b);
		if (a == b) continue;
		p[b] = a, ans += c, edge[ ++ cnt] = edge[i];
		if ( ++ sum == n - 1) break;
	}
	m1 = cnt;
	for (register int S = 0, Full = (1 << m2), sum = 0; S < Full; ++ S)
	{
		for (register int i = 1; i <= n + m2; ++ i) p[i] = i;
		for (register int i = 1; i <= m1; ++ i) Edge[i] = edge[i];
		cnt = m1, res = 0, sum = 0;
		for (register int i = 1; i <= m2; ++ i)
		{
			if ((S >> (i - 1)) & 1)
			{
				res += v[i][0];
				for (register int j = 1; j <= n; ++ j)
				{
					Edge[ ++ cnt] = {j, n + i, v[i][j]};
				}
			}
		}
		sort (Edge + 1, Edge + cnt + 1);
		for (register int i = 1; i <= cnt; ++ i)
		{
			int a = Edge[i].a, b = Edge[i].b, c = Edge[i].c;
			a = find(a), b = find(b);
			if (a == b) continue;
			p[b] = a, res += c;
			if (res >= ans) break;
			if ( ++ sum == n + m2 - 1) break;
		}
		ans = min(ans, res);
	}
	print(ans);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out","w", stdout);
	read(n), read(m1), read(m2);
	solve1();
	return 0;
}

namespace Fast_read
{
	int op, stk[35], top = 0; 
	char c;
	template <typename T>
	inline void read(T &w)
	{
		w = 0, op = 1;
		do {c = getchar();}while ((c < '0' || c > '9') && c != '-');
		if (c == '-') op = -1, c = getchar();
		do {w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();}while (c >= '0' && c <= '9');
		w *= op;
	}
	template <typename T>
	inline void print(T ans)
	{
		top = 0;
		if (ans < 0) putchar('-'), ans = -ans;
		do {stk[ ++ top] = ans % 10, ans /= 10;}while (ans);
		while (top) putchar(stk[top -- ] ^ 48);
	}
};
