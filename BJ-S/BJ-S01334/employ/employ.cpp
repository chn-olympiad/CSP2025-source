#include <cstdio>

#define N (500 + 10)
typedef long long ll;
#define mod 998244353ll

int s[N], c[N];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%1d", &s[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += s[i];
    if (cnt < m)
    {
        printf("0\n");
        return 0;
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i, ans %= mod;
    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}