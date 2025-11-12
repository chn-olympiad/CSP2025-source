#include <bits/stdc++.h>

using namespace std;

namespace FastRead{
    char buf[1 << 20 | 5], *s = buf, *t = buf;
    #define gc() (s == t && (t = (s = buf) + fread(buf, 1, 1 << 20, stdin), s == t) ? EOF : *s ++ )
    template <typename T>
    inline void Read(T &x)
    {
        char ch = gc();
        int f = 0;
        x = 0;
        while(ch < '0' || ch > '9') f = ch == '-', ch = gc();
        while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
        f && (x = -x);
    }
    inline void Read(char *str)
    {
        while((*str = gc()) <= 32 || *str >= 127) ;
        str ++ ;
        while((*str = gc()) > 32 && *str < 127) str ++ ;
        *str = 0;
    }
}
using FastRead::Read;

typedef long long LL;

const int N = 5e6 + 5, S = 26, K = 18;

bool STT;
int n, m;
char s1[N], s2[N], s[N];
int tr[N][S], fail[N], cnt[N], tot;
int q[N], hh, tt;
bool EDD;

inline void Insert()
{
    int n = strlen(s1 + 1), n1 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        s[ ++ n1] = s1[i];
        s[ ++ n1] = s2[i];
    }
    
    int u = 0;
    for(int i = 1; i <= n1; i ++ )
    {
        int ch = s[i] - 'a';
        if(!tr[u][ch]) tr[u][ch] = ++ tot;
        u = tr[u][ch];
    }
    cnt[u] ++ ;
}
inline void Build()
{
    hh = 0, tt = -1;
    for(int i = 0; i < S; i ++ )
    {
        if(tr[0][i]) fail[tr[0][i]] = 0, q[ ++ tt] = tr[0][i];
        else tr[0][i] = 0;
    }
    while(hh <= tt)
    {
        int u = q[hh ++ ];
        cnt[u] += cnt[fail[u]];
        for(int i = 0; i < S; i ++ )
        {
            if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q[ ++ tt] = tr[u][i];
            else tr[u][i] = tr[fail[u]][i];
        }
    }
}
inline LL Query()
{
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    if(n != m) return 0;
    int l = 1, r = n;
    while(s1[l] == s2[l]) l ++ ;
    while(s1[r] == s2[r]) r -- ;
    // printf("%s %s\n", s1 + 1, s2 + 1);
    // printf("!%d %d\n", l, r);
    LL ans = 0;
    for(int i = 1, u = 0; i <= n; i ++ )
    {
        u = tr[tr[u][(int)s1[i] - 'a']][(int)s2[i] - 'a'];
        if(i >= r) ans += cnt[u];
    }
    for(int i = l + 1, u = 0; i <= n; i ++ )
    {
        u = tr[tr[u][(int)s1[i] - 'a']][(int)s2[i] - 'a'];
        if(i >= r) ans -= cnt[u];
    }
    return ans;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    Read(n), Read(m);
    for(int i = 1; i <= n; i ++ ) Read(s1 + 1), Read(s2 + 1), Insert();
    Build();
    for(int i = 1; i <= m; i ++ ) Read(s1 + 1), Read(s2 + 1), printf("%lld\n", Query());
    return 0;
}