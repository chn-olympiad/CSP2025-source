#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <map>
#include <set>

namespace uvu
{
#define LOCAL __________DONT_DEFINE_ME___________
#define ll long long
#define inf 0x3f3f3f3f
// #define int long long
// #define inf 0x3f3f3f3f3f3f3f3fll
#define infll 0x3f3f3f3f3f3f3f3fll
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define gline debug("now is #%d\n", __LINE__)
#define mkp std::make_pair
#define pii std::pair <int, int>
#define fi first
#define se second
char _ST_;
char getc() { return getchar(); }
void putc(char c) { putchar(c); }
template <typename T = int> T read()
{
	T x = 0, f = 1; char c = getc();
	for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
	for(;  isdigit(c); c = getc()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}
template <typename T> void print(T x, char c)
{
static int sta[1 << 20], top;
	top = 0;
	if(x < 0) putc('-'), x *= -1;
	if(!x) sta[++top] = 0;
	for(; x; x /= 10) sta[++top] = x % 10;
	for(; top; putc(sta[top--] ^ 48));
	if(c) putc(c);
}
void printf(const char *s) { for(; *s; s++) putc(*s); }
template <typename T, typename ... Args>
void printf(const char *s, T x, Args ... rest)
{
	for(; *s; s++)
	{
		if(*s != '%') { putc(*s); continue; }
		s++; if(*s == 'c') putc(x);
		else if(*s == 'd') print(x, 0);
		printf(s + 1, rest ...);
		return;
	}
}
int readstr(char *str, int base)
{
	int idx = base - 1; char c = getc();
	for(; !(isdigit(c) || isalpha(c) || c == '.' || c == '#'); c = getc());
	for(;   isdigit(c) || isalpha(c) || c == '.' || c == '#' ; c = getc()) str[++idx] = c;
	return idx - base + 1;
}
template <typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }
template <typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
#define mod 998244353
// #define mod 1000000007
int sm(int x) { return x >= mod ? x - mod : x; }
void plus_(int &x, int y) { x = sm(x + y); }
void mul_(int &x, int y) { x = 1ll * x * y % mod; }
int ksm(int a, int b) { int res = 1; for(; b; b >>= 1, mul_(a, a)) if(b & 1) mul_(res, a); return res; }

#define N 10110
#define M 1000010
int n, m, K;
struct edge
{
	int x, y, z;
	bool operator < (const edge &B) const
	{
		return z < B.z;
	}
}e0[M], a[11][N];
int c[11];
int fa[N]; int Find(int x) { return fa[x] == x ? x : (fa[x] = Find(fa[x])); }
int lim[N], sz[N];

void solve()
{
	// memset(h, idx = -1, sizeof(h));
	n = read(), m = read(), K = read();
	for(int i = 1; i <= m; i++) e0[i].x = read(), e0[i].y = read(), e0[i].z = read();
	int DT = n + 1;
	for(int i = 0; i < K; i++)
	{
		c[i] = read();
		for(int j = 1; j <= n; j++) a[i][j].x = DT + i, a[i][j].y = j, a[i][j].z = read();//, printf(" [%d %d %d]\n", a[i][j].x, a[i][j].y, a[i][j].z);
		std::sort(a[i] + 1, a[i] + 1 + n);
		lim[i] = n;
	}
	int top = 0;
	std::sort(e0 + 1, e0 + 1 + m);
	std::iota(fa + 1, fa + 1 + n, 1);
	for(int i = 1; i <= m; i++)
	{
		int x = Find(e0[i].x), y = Find(e0[i].y);
		if(x == y) continue;
		a[K][++top] = e0[i];
		fa[x] = y;
	}
	lim[K] = top;
	ll ans = infll;
	for(int S = 0; S < (1 << K); S++)
	{
		std::iota(fa + 1, fa + 1 + n + K, 1);
		std::fill(sz + 1, sz + 1 + n + K, 1);
		top = 0;
static int sta[N], pos[N];
		sta[top++] = K; pos[K] = 1;
		int tot = 0; ll now = 0;
		for(int i = 0; i < K; i++) if(S >> i & 1) sta[top++] = i, pos[i] = 1, now += c[i];
		while(tot < n + top - 2)
		{
			int p = -1, val = inf, x, y;
			for(int _ = 0, i; _ < top; _++) 
			{
				i = sta[_];
				while(pos[i] <= lim[i] && Find(a[i][pos[i]].x) == Find(a[i][pos[i]].y)) pos[i]++;
				if(pos[i] <= lim[i] && a[i][pos[i]].z <= val) val = a[i][pos[i]].z, p = i;
			}
			if(!~p) break;
			// printf("[%d %d %d]\n", a[p][pos[p]].x, a[p][pos[p]].y, val);
			tot++;
			now += val;
			x = Find(a[p][pos[p]].x);
			y = Find(a[p][pos[p]].y);
			if(sz[x] > sz[y]) x ^= y ^= x ^= y;
			fa[x] = y; sz[y] += sz[x];
			pos[p]++;
		}
		// printf("S = %d, now = %d\n", S, now);
		ckmin(ans, now);
	}
	print(ans, '\n');
}

void init()
{

}

char _ED_;
void mian()
{
	debug("%.3f MB\n", abs(&_ST_ - &_ED_) / 1024.0 / 1024);
	int T = 1;
	init();
	for(; T; T--, solve());
}


#ifdef int 
	#undef int
#endif
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	uvu::mian(); return 0;
}
// ningago loves LinkWish forever ^w^