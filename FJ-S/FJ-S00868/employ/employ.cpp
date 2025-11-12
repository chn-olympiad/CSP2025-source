#include <iostream> 

using namespace std;

namespace Fast_read
{
	template <typename T>
	inline void read(T &w) ;
	template <typename T>
	inline void print(T ans) ;
	inline void read(char *s, int &len) ;
};
using namespace Fast_read;

const int mod = 998244353;

int n, m, st[510], w[510];
char str[510];
long long fact[510], ans = 0;

void dfs(int u, int res)
{
	if (res >= m)
	{
		ans += fact[n - u + 1];
		if (ans >= mod) ans -= mod;
		return ;
	}
	if (u > n) return ;
	for (register int i = 1; i <= n; ++ i)
	{
		if (st[i]) continue;
		st[i] = 1;
		if (u - 1 - res >= w[i]) dfs(u + 1, res);
		else dfs(u + 1, res + (str[u] == '1'));
		st[i] = 0;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w", stdout);
	read(n), read(m), read(str, n = 0), fact[0] = 1;
	for (register int i = 1; i <= n; ++ i) read(w[i]), fact[i] = fact[i - 1] * i % mod;
	dfs(1, 0), print(ans);
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
	
	inline void read(char *s, int &len)
	{
		do {c = getchar();}while (c != '0' && c != '1');
		do {s[ ++ len] = c, c = getchar();}while (c == '0' || c == '1');
	}
};
