#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

namespace Fast_read
{
	template <typename T>
	inline void read(T &w) ;
	template <typename T>
	inline void print(T ans) ;
};
using namespace Fast_read;

const int N = 100010;

int n, m, now = 0;
struct node
{
	long long v[3];
	int id;
	bool operator< (const node &t)const
	{
		return v[1] - v[0] > t.v[1] - t.v[0];
	}
}w[N];
long long p[N], f[2][210][210], ans = 0;

void dfs(int u, int a, int b, int c, long long res)
{
	if (u > n)
	{
		ans = max(ans, res);
		return ;
	}
	if (a < m) dfs(u + 1, a + 1, b, c, res + w[u].v[0]);
	if (b < m) dfs(u + 1, a, b + 1, c, res + w[u].v[1]);
	if (c < m) dfs(u + 1, a, b, c + 1, res + w[u].v[2]);
}

void solve()
{
	read(n), m = (n >> 1), ans = 0;
	for (register int i = 1; i <= n; ++ i)
	{
		for (register int j = 0; j < 3; ++ j)
		{
			read(w[i].v[j]);
		}
		w[i].id = i;
	}
	if (n <= 10)
	{
		dfs(1, 0, 0, 0, 0);
		print(ans), puts("");
		return ;
	}
	if (n <= 400)
	{
		now = 0;
		for (register int j = 0; j <= m; ++ j)
		{
			for (register int k = 0; k <= m; ++ k)
			{
				f[now][j][k] = -1e18;
			}
		}
		f[now][0][0] = 0;
		for (register int i = 1; i <= n; ++ i)
		{
			now ^= 1;
			for (register int j = 0; j <= m; ++ j)
			{
				for (register int k = 0; k <= m; ++ k)
				{
					f[now][j][k] = -1e18;
					if (j + k > i || i - j - k > m) continue;
					if (j > 0) f[now][j][k] = max(f[now][j][k], f[now ^ 1][j - 1][k] + w[i].v[0]);
					if (k > 0) f[now][j][k] = max(f[now][j][k], f[now ^ 1][j][k - 1] + w[i].v[1]);
					if (i - j - k > 0) f[now][j][k] = max(f[now][j][k], f[now ^ 1][j][k] + w[i].v[2]);
				}
			}
		}
		for (register int i = 0; i <= m; ++ i)
		{
			for (register int j = 0; j <= m; ++ j)
			{
				ans = max(ans, f[now][i][j]);
			}
		}
		print(ans), puts("");
		return ;
	}
	sort (w + 1, w + n + 1);
	for (register int i = 1; i <= m; ++ i) ans += w[i].v[1], p[i] = w[i].v[2] - w[i].v[1];
	for (register int i = m + 1; i <= n; ++ i) ans += w[i].v[0], p[i] = w[i].v[2] - w[i].v[0];
	sort (p + 1, p + n + 1);
	for (register int i = n, j = 0; i >= 1 && j < m; -- i)
	{
		if (p[i] <= 0) break;
		ans += p[i], ++ j;
	}
	print(ans), puts("");
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);
	int Q;
	read(Q);
	while (Q -- ) solve();
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
