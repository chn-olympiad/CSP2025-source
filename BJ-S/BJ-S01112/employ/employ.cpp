//100+56+50+12
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int mod = 998244353;
char s[505];
int a[505], p[505];
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), p[i] = i;
    if (n <= 10)
    {

        int ans = 0;
        do
        {
            int res = 0, cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                // printf("%lld ", cnt);
                if (s[i] == '0' || cnt >= a[p[i]])
                {
                    cnt++;
                }
                else
                    res++;
            }
            // puts("");
            if (res >= m)
                ans++, ans %= mod;
        } while (next_permutation(p + 1, p + n + 1));
        printf("%lld", ans);
    }
    // else if (m == 1)
    // {
    //     int cnt = n;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (a[i] == 0)
    //             cnt--;
    //     }
    //     int res = cnt;
    //     for (int i = 1; i <= n - 1; i++)
    //         res = res * i
    // }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0 || s[i] == '0')
            {
                puts("0");
                return 0;
            }
        }
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * i % mod;
        }
        printf("%lld", res);
        // int cnt = n;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (s[i] == '0')
        //     {
        //         cnt--;
        //     }
        // }
        // if (cnt >= m)
        // {
        //     int fc = 1;
        //     for (int i = 1; i <= n; i++)
        //     {
        //         fc = fc * i % mod;
        //     }
        // }
    }
    return 0;
}