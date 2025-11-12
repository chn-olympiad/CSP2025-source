#include <bits/stdc++.h>
using namespace std;
const unsigned int mod = 998244353;

int ok[19], c[19];
unsigned int dp[262144][19];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%1d", &ok[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &c[i]);
    }
    dp[0][0] = 1;
    for(int i = 0;i < (1 << n) - 1;i++)
    {
        int popcnt = __builtin_popcount(i);
        for(int j = 1;j <= n;j++)
        {
            if(!((i >> (j - 1)) & 1))
            {
                for(int k = 0;k <= m;k++)
                {
                    if(dp[i][k])
                    {
                        unsigned int& pos = dp[i | (1 << (j - 1))][min(m, k + (ok[popcnt + 1] && c[j] > (popcnt - k)))];
                        pos = (pos + dp[i][k]) % mod;
                    }
                }
            }
        }
    }
    printf("%u\n", dp[(1 << n) - 1][m]);
    return 0;
}
