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

#define N 100010
int n;
int a[N][3];
int val[N], d[N];
int cnt[3];
int sta[N], top;

void solve()
{
	// memset(h, idx = -1, sizeof(h));
	n = read(); cnt[0] = cnt[1] = cnt[2] = 0;
	ll ans = 0; top = 0;
	for(int i = 1; i <= n; i++) for(int j = 0; j < 3; j++) a[i][j] = read();
	for(int i = 1; i <= n; i++)
	{
		d[i] = std::max_element(a[i], a[i] + 3) - a[i];
		val[i] = a[i][d[i]];
		cnt[d[i]]++; ans += val[i];
	}
	int lim = n / 2;
	if(cnt[0] <= lim && cnt[1] <= lim && cnt[2] <= lim) return print(ans, '\n');
	int p = std::max_element(cnt, cnt + 3) - cnt;
	for(int i = 1; i <= n; i++) if(d[i] == p)
	{
		int val = -inf;
		for(int j = 0; j < 3; j++) if(j != p) ckmax(val, a[i][j] - a[i][p]);
		sta[++top] = val;
	}
	std::sort(sta + 1, sta + 1 + top, [&](int x, int y) -> bool { return x > y; });
	for(int i = 1; i <= cnt[p] - lim; i++) ans += sta[i];
	// gline;
	print(ans, '\n');
}

void init()
{

}

char _ED_;
void mian()
{
	debug("%.3f MB\n", abs(&_ST_ - &_ED_) / 1024.0 / 1024);
	int T = read();
	init();
	for(; T; T--, solve());
}


#ifdef int 
	#undef int
#endif
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	uvu::mian(); return 0;
}
// ningago loves LinkWish forever ^w^