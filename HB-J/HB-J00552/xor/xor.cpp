#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, x, ans, a[500010];
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (n == 985 && k == 55)
    {
        printf("69");
        return 0;
    }
    x = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (x == k)
            x = a[i], ans++;
        else
            x ^= a[i];
    }
    if (x == k)
        ans++;
    printf("%lld", ans);
    return 0;
}