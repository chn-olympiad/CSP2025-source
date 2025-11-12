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

const int N = 505, P = 998244353;

int n, m;
char s[N];
int cnt[N], sum[N];
LL fact[N];
LL f[N][N], g[N][N];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    Read(n), Read(m), Read(s + 1);
    for(int i = 1; i <= n; i ++ )
    {
        s[i] -= '0';
        int x;
        Read(x);
        cnt[x] ++ ;
    }
    for(int i = 0; i <= n; i ++ ) sum[i] = cnt[i] + (i > 0 ? sum[i - 1] : 0);
    
    fact[0] = 1;
    for(int i = 1; i <= n; i ++ ) fact[i] = fact[i - 1] * i % P;

    f[0][0] = 1;
    LL ans = 0;
    for(int i = 0; i <= n - m; i ++ )
    {
        memset(g, 0, sizeof g);
        for(int j = 0; j <= n; j ++ )
            for(int k = 0; k <= n - j; k ++ )
                if(f[j][k])
                {
                    if(j + k == n)
                    {
                        if(j == sum[i])
                        {
                            // printf("*%d %d %d %lld %lld\n", i, j, k, f[j][k], f[j][k] * fact[k]);
                            ans = (ans + f[j][k] * fact[k]) % P;
                        }
                    }
                    else
                    {
                        if(s[j + k + 1])
                        {
                            g[j + 1][k] = (g[j + 1][k] + f[j][k] * (sum[i] - j)) % P;
                            f[j][k + 1] = (f[j][k + 1] + f[j][k]) % P;
                        }
                        else
                        {
                            g[j + 1][k] = (g[j + 1][k] + f[j][k] * (sum[i] - j)) % P;
                            g[j][k + 1] = (g[j][k + 1] + f[j][k]) % P;
                        }
                    }
                }
        
        if(cnt[i + 1])
        {
            for(int x = 1; x <= cnt[i + 1]; x ++ )
            {
                memset(f, 0, sizeof f);
                for(int j = 0; j <= n; j ++ )
                    for(int k = 0; k <= n - j; k ++ )
                        if(g[j][k])
                        {
                            f[j][k] = (f[j][k] + g[j][k]) % P;
                            if(k) f[j + 1][k - 1] = (f[j + 1][k - 1] + g[j][k] * k) % P;
                        }
                memcpy(g, f, sizeof f);
            }
        }
        else
        {
            memcpy(f, g, sizeof f);
        }
    }

    printf("%lld\n", ans);
    return 0;
}