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

#define N 510
int n, m;
int C[N][N], fac[N];
char str[N];
int a[N], c[N];
int cnt[N], pre[N], suf[N];
int dp[2][N][N], tmp[N][N];
int op;

void solve()
{
    // memset(h, idx = -1, sizeof(h));
    n = read(), m = read(); readstr(str, 1);
    for(int i = 1; i <= n; i++) a[i] = (str[i] ^ 48), cnt[c[i] = read()]++;
    dp[op = 0][0][0] = 1;
    for(int i = 0; i <= n; i++) pre[i] = suf[i] = cnt[i];
    for(int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    for(int i = n - 1; ~i; i--) suf[i] += suf[i + 1];
    for(int i = 1; i <= n; i++)
    {
        op ^= 1;
        for(int j = 0; j <= i; j++) for(int k = 0; k <= i; k++) if(dp[op ^ 1][j][k])
        {
            int v = dp[op ^ 1][j][k]; dp[op ^ 1][j][k] = 0;
            if(a[i] == 1) plus_(dp[op][j][k + 1], v);
            else plus_(tmp[j][k + 1], v);
            if(pre[j] - (i - 1 - k) > 0)
            plus_(tmp[j][k], 1ll * v * (pre[j] - (i - 1 - k)) % mod);
        }
        for(int j = 0; j <= i; j++) for(int k = 0; k <= i; k++) if(tmp[j][k])
        {
            int v = tmp[j][k]; tmp[j][k] = 0;
            for(int z = 0; z <= k && z <= cnt[j + 1]; z++)
                plus_(dp[op][j + 1][k - z], 1ll * C[cnt[j + 1]][z] * C[k][z] % mod * fac[z] % mod * v % mod);
        }
    }
    int ans = 0;
    for(int j = 0; j <= n - m; j++) if(dp[op][j][suf[j + 1]])
    {
        plus_(ans, 1ll * dp[op][j][suf[j + 1]] * fac[suf[j + 1]] % mod);
    }
    print(ans, '\n');
}

void init()
{
    for(int i = 0; i < N; i++) for(int j = C[i][0] = C[i][i] = 1; j < i; j++) C[i][j] = sm(C[i - 1][j] + C[i - 1][j - 1]);
    for(int i = fac[0] = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
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
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    uvu::mian(); return 0;
}
// ningago loves LinkWish forever ^w^