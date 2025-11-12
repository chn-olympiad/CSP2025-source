#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long ans, n, a[5005];
bool vis[5005];

void f(long long step, long long sum, long long maxai, long long m)
{
    if (step > n)
    {
        if (m >= 3 && sum > maxai * 2)
            ans ++;
        return;
    }
    vis[step] = 1;
    f(step + 1, sum + a[step], max(maxai, a[step]), m + 1);
    vis[step] = 0;
    f(step + 1, sum, maxai, m);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    f(1, 0, 0, 0);
    printf("%lld", ans % mod);
    return 0;
}
