#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int NR = 510;
const long long mod = 998244353;
int s[NR];
int c[NR];
int p[NR];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%1d", &s[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        p[i] = i;
    }
    long long ans = 0;
    do
    {
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (cnt >= c[p[i]]) cnt ++;
            else
            {
                if (s[i] == 0) cnt ++;
            }
        }
        if (n - cnt >= m) ans ++;
        if (ans >= mod) ans -= mod;
    } while (next_permutation(p + 1, p + n + 1));
    printf("%lld\n", ans);
    return 0;
}
