#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5009;

const LL mod = 998244353;

int n, a[N];

LL ans;

LL f[N][N];

LL qp(LL a, LL b)
{
    LL r = 1;
    for (;b;b >>= 1, a = a * a % mod)
        (b & 1) ? r = r * a % mod : 0;
    return r;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1;i <= n;++ i)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    ans = (qp(2, n) - 1) % mod;
    f[0][0] = 1;
    for (int i = 1;i <= n;++ i)
    {
        for (int j = 0;j <= a[i];++ j)
            ans = (ans - f[i - 1][j]) % mod;
        for (int j = 0;j <= 5000;++ j)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
                f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
        }
    }
    printf("%lld\n", (ans % mod + mod) % mod);
    fclose(stdin);
    fclose(stdout);

    return 0;
}