#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 509;

int n, m;

char a[N];

int c[N];

const LL mod = 998244353;

void upt(LL& a, LL b)
{
    (a += b) %= mod;
}

namespace BF
{
    int p[N], ans, vis[N];
    void dfs(int i)
    {
        if (i > n)
        {
            int tot = 0;
            for (int i = 1;i <= n;++ i)
                if (!a[i] || tot >= c[p[i]])
                    ++ tot;
            ans += (tot <= m);
            return;
        }
        for (int j = 1;j <= n;++ j)
            if (!vis[j])
            {
                p[i] = j, vis[j] = 1;
                dfs(i + 1);
                vis[j] = 0;
            }
    }
    void main()
    {
        dfs(1);
        printf("%d\n", ans);
    }
}

namespace BF1
{
    LL f[19][(1 << 18) + 9];
    void main()
    {
        f[0][0] = 1;
        for (int s = 1;s < (1 << n);++ s)
        {
            int i = __builtin_popcount(s);
            for (int x = 1;x <= n;++ x)
                if (s >> (x - 1) & 1)
                {
                    for (int tot = 0;tot < i;++ tot)
                    {
                        if ((!a[i] || tot >= c[x]))
                            upt(f[tot + 1][s], f[tot][s ^ (1 << (x - 1))]);
                        else
                            upt(f[tot][s], f[tot][s ^ (1 << (x - 1))]);
                    }
                }
        }
        LL ans = 0;
        for (int i = 0;i <= m;++ i)
            ans = (ans + f[i][(1 << n) - 1]) % mod;
        printf("%lld\n", ans);
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d%s", &n, &m, a + 1);
    m = n - m;
    for (int i = 1;i <= n;++ i)
        scanf("%d", &c[i]), a[i] -= '0';
    if (n <= 10)
        BF::main();
    else if (n <= 18)
        BF1::main();
    else if (!m)
    {
        int ans = 1;
        for (int i = 1;i <= n;++ i)
            ans &= (a[i] && (c[i] > 0));
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}