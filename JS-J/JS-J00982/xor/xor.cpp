#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500005], r, cnt, pre[500005];
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (n <= 1000)
    {
        for (int i = 1; i <= n; i++)
        {
            int l = 0;
            for (int j = i; j > r; j--)
            {
                l ^= a[j];
                if (l == k)
                {
                    cnt++, r = i;
                    break;
                }
            }
        }
    }
    else if (k <= 1)
    {
        if (k)
        {
            for (int i = 1; i <= n; i++)
                if (a[i])
                    cnt++;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (!a[i] || (a[i] && a[i - 1]))
                    cnt++;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
