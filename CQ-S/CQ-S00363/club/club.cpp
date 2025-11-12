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

const int N = 1e5 + 5;

int n, m = 3;
int a[N][3], p[N];
int cnt[3];
int d[N], k;

inline void Solve()
{
    int sum = 0;
    Read(n);
    for(int i = 1; i <= n; i ++ )
    {
        int p = 0;
        for(int j = 0; j < m; j ++ )
        {
            Read(a[i][j]);
            if(a[i][j] > a[i][p]) p = j;
        }
        sum += a[i][p];
        ::p[i] = p;
        cnt[p] ++ ;
    }
    for(int x = 0; x < m; x ++ )
        if(cnt[x] > n / 2)
        {
            k = 0;
            for(int i = 1; i <= n; i ++ )
                if(p[i] == x)
                {
                    int w = 0;
                    for(int y = 0; y < m; y ++ )
                        if(y != x)
                            w = max(w, a[i][y]);
                    d[ ++ k] = a[i][x] - w;
                }
            sort(d + 1, d + k + 1);
            for(int i = 1; i <= k - n / 2; i ++ ) sum -= d[i];
        }
    printf("%d\n", sum);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    Read(T);
    while(T -- ) Solve();

    return 0;
}