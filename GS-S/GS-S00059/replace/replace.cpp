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

#define N 5000100
#define M 200010
int n, m;
char str1[N], str2[N];
ll ans[M];
int pos1[M], pos2[M];
int id1[M], id2[M];
int tr[N][26], fail[N], nidx;
int dep[N];
int ins(char *str, int n)
{
    // debug("n = %d\n", n);
    int p = 0;
    for(int i = 1; i <= n; i++)
    {
        // if(i % 1000 == 0) debug("nidx = %d (%c)\n", nidx, str[i]);
        if(!tr[p][str[i] - 'a'])
            tr[p][str[i] - 'a'] = ++nidx;
        p = tr[p][str[i] - 'a'];
        dep[p] = i;
    }
    return p;
}
int q[N], head, tail;
int h[N], e[N], ne[N], idx = -1;
void add_edge(int x, int y) { ne[++idx] = h[x], h[x] = idx, e[idx] = y; }
int dfn[N], out[N], dfncnt;
// void dfs0(int k)
// {
//     dfn[k] = ++dfncnt;
//     // debug("dfn[%d] = %d\n", k, dfn[k]);
//     for(int i = h[k]; ~i; i = ne[i]) dfs0(e[i]);
//     out[k] = dfncnt;
// }
void buildAC()
{
    head = 1;
    for(int i = 0; i < 26; i++) if(tr[0][i]) q[++tail] = tr[0][i];
    for(int k; head <= tail; )
    {
        k = q[head++];
        for(int i = 0; i < 26; i++) 
        {
            if(!tr[k][i]) tr[k][i] = tr[fail[k]][i];
            else fail[q[++tail] = tr[k][i]] = tr[fail[k]][i];
        }
    }
    for(int i = 1; i <= nidx; i++) /* debug("fail[%d] = %d\n", i, fail[i]), */ add_edge(fail[i], i);
    // gline;
    // dfs0(0);
    // gline;
    q[tail = 1] = 0; dfn[0] = ++dfncnt;
    while(tail)
    {
        int k = q[tail];
        if(!~h[k]) out[k] = dfncnt, tail--;
        else dfn[q[++tail] = e[h[k]]] = ++dfncnt, h[k] = ne[h[k]];
    }
}
std::vector <pii> nvec[N];
std::vector <pii> qvec[N];
int trr[N];
void ins(int x, int z) { for(; x <= dfncnt; x += x & (-x)) trr[x] += z; }
int query(int x) { int res = 0; for(; x; x -= x & (-x)) res += trr[x]; return res;}

void solve()
{
    memset(h, idx = -1, sizeof(h));
    n = read(), m = read();
    for(int i = 1, len; i <= n; i++)
    {
        len = readstr(str1, 1);
        len = readstr(str2, 1);
        pos1[i] = ins(str1, len);
        pos2[i] = ins(str2, len);
    }
    buildAC();
    for(int i = 1, len1, len2; i <= m; i++)
    {
        len1 = readstr(str1, 1);
        len2 = readstr(str2, 1);
        if(len1 != len2) continue;
        int p1 = 0, p2 = 0;
        int pre = 0, suf = len1 + 1;
        for(; pre < len1 && str1[pre + 1] == str2[pre + 1]; pre++);
        for(; suf > 1 && str1[suf - 1] == str2[suf - 1]; suf--);
        // debug("len1 = %d, pre = %d, suf = %d\n", len1, pre, suf);
        // if(i == 101) printf("pre = %d, suf = %d\n", pre, suf);
        // if(i == 101)
        // {
        //     for(int i = 1; i <= len1; i++) putc(str1[i]);
        //     putc('\n');
        //     for(int i = 1; i <= len1; i++) putc(str2[i]);
        //     putc('\n');
        // }
        for(int j = 1; j <= len1; j++)
        {
            p1 = tr[p1][str1[j] - 'a'];
            p2 = tr[p2][str2[j] - 'a'];
            if(j + 1 < suf) continue;
            // if(i == 101) printf("j = %d, p = [%d %d]\n", j, p1, p2);
            // if(dfn[p1] <= dfn[p2] && dfn[p2] <= out[p1]) continue;
            // if(dfn[p2] <= dfn[p1] && dfn[p1] <= out[p2]) continue;
            qvec[dfn[p1]].push_back(mkp(dfn[p2], i));
        }
        p1 = 0, p2 = 0;
        for(int j = 1; j <= len1; j++)
        {
            p1 = tr[p1][str1[j] - 'a'];
            p2 = tr[p2][str2[j] - 'a'];
            while(p1 && j - dep[p1] <= pre) p1 = fail[p1];
            while(p2 && j - dep[p2] <= pre) p2 = fail[p2];
            if(j + 1 < suf) continue;
            // if(i == 101) printf("j = %d, p = [%d %d]\n", j, p1, p2);
            // if(dfn[p1] <= dfn[p2] && dfn[p2] <= out[p1]) continue;
            // if(dfn[p2] <= dfn[p1] && dfn[p1] <= out[p2]) continue;
            qvec[dfn[p1]].push_back(mkp(-dfn[p2], i));
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int x = pos1[i], y = pos2[i];
        // if(dfn[x] <= dfn[y] && dfn[y] <= out[x]) debug("AAA [%d %d]\n", x, y);
        // if(dfn[y] <= dfn[x] && dfn[x] <= out[y]) debug("BBB [%d %d]\n", x, y);
        nvec[dfn[x]].push_back(mkp(dfn[y], out[y]));
        nvec[out[x] + 1].push_back(mkp(-dfn[y], out[y]));
    }
    for(int i = 1; i <= dfncnt; i++)
    {
    // gline;
        for(pii _ : nvec[i])
        {
            int z = 1;
            if(_.fi < 0) _.fi *= -1, z = -1;
            ins(_.fi, z); ins(_.se + 1, -z);
        }
    // gline;
        for(pii _ : qvec[i])
        {
            int z = 1;
            if(_.fi < 0) _.fi *= -1, z = -1;
            // if(_.se == 101)
            //     printf("ans[%d] += %d * %d\n", _.se, query(_.fi), z);
            ans[_.se] += query(_.fi) * z;
        }
    // gline;
    }
    for(int i = 1; i <= m; i++) print(ans[i], '\n');
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
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    uvu::mian(); return 0;
}
// ningago loves LinkWish forever ^w^