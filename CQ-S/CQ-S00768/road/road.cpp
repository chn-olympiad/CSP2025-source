#include "iostream"
#include "algorithm"
#include "climits"
#include "cstring"
#include "cmath"
#define int long long

using ll = long long;
const int N = 2e6 + 5;

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(ll x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

int n, m, k;

int head[N];
int s[N];
int c[11][N];
int ans = 1e18;

struct Node
{
	int x, y, w, kind;
	bool operator < (const Node &o)
	const
	{
		return w < o.w;
	}
}a[N];

inline int find(int x)
{
	return x == s[x] ? x : s[x] = find(s[x]);
}

inline void init()
{
	for(int i = 1; i <= n; i++)
	{
		s[i] = i;
	}
}

bool f;

inline int MST(Node a[], int tot)
{
	int ret = 0;
	std :: sort(a + 1, a + tot + 1);
	int cnt = 0;
	init();
	for(int i = 1; i <= tot; i++)
	{
		int x = find(a[i].x);
		int y = find(a[i].y);
		if(x == y) continue;
		s[x] = y;
		cnt++;
		ret += a[i].w;
		if(a[i].kind) f = true;
		if(ret >= ans) return -1;
		if(cnt == n - 1) break; 
	}
	return ret;
}

inline void dfs(int last, int s, int cnt, Node b[])
{
	if(last != 0) s += c[last][1] + c[last][last + 1];
	if(s > ans) return;
	if(last > k) return;
	if(last != 0)
	{
		for(int i = 2; i <= n + 1; i++)
		{
			b[++cnt].x = last, b[cnt].y = i - 1, b[cnt].w = c[last][i], b[cnt].kind = 1;
			b[++cnt].x = i - 1, b[cnt].y = last, b[cnt].w = c[last][i], b[cnt].kind = 1;
		}
		f = false;
		int t = MST(b, cnt);
		if(!f) s -= c[last][last + 1];
		if(t != -1 && t + s < ans)
		{
			ans = t + s;
//			std :: cout << last << ' ' << ans << '\n';
		}
	}
	for(int i = last + 1; i <= k; i++)
	{
		dfs(i, s, cnt, a);
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std :: cin >> n >> m >> k;
	
	int tot = 0;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		std :: cin >> u >> v >> w;
		a[++tot].x = u, a[tot].y = v, a[tot].w = w;
		a[++tot].x = v, a[tot].y = u, a[tot].w = w;
	}
	
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			std :: cin >> c[i][j];	
		}
	}
	
	ans = MST(a, tot);
	
	dfs(0, 0, tot, a);

	write(ans);
	
	return 0;
}

/*
5 5 2
1 2 4
1 3 8
1 4 7
2 5 3
2 4 8
8 1 1 1 1 1
0 0 0 0 0 0
*/

/*
4 8 0
1 2 114514
1 2 114514
1 2 114514
1 2 114514
1 1 0
1 2 0
1 3 0
1 4 0
*/
