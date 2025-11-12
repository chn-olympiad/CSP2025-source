#include<cstdio>
#include<algorithm>
using namespace std;

const int p = 998244353;
int n, m, c[505], ss, f[20][1 << 18];
bool s[505];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%01d", &s[i]);
        ss += s[i];
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    if(m == n)
    {
        if(ss < n)
        {
            printf("0");
            return 0;
        }
        for(int i = 1; i <= n; i++)
            if(c[i] == 0)
            {
                printf("0");
                return 0;
            }
        int ans = 1;
        for(int i = 1; i <= n; i++)
            ans = 1ll * ans * i % p;
        printf("%d", ans);
        return 0;
    }
    f[0][0] = 1;
    for(int k = 1; k < (1 << n); k++)
    {
        int i = __builtin_popcount(k);
        for(int j = !s[i]; j <= i; j++)
            for(int l = 1; l <= n; l++)
                if(k & (1 << l - 1))
                {
                    int ll = k - (1 << l - 1);
                    if(!s[i]) f[j][k] = (f[j][k] + f[j - 1][ll]) % p;
                    else
                    {
                        if(j - 1 >= c[l]) f[j][k] = (f[j][k] + f[j - 1][ll]) % p;
                        if(j < c[l]) f[j][k] = (f[j][k] + f[j][ll]) % p;
                    }
                }
    }
    int ans = 0;
    for(int i = 0; i <= n - m; i++)
        ans = (ans + f[i][(1 << n) - 1]) % p;
    printf("%d", ans);
    return 0;
}
