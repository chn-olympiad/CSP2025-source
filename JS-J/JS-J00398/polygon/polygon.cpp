#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,k[5001],dp[25000001],ans,sum,t = 1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",k + i);
    sort(k + 1,k + n + 1);
    if (k[1] == k[n])
    {
        ans = 1;
        for (int i = 1; i <= n; i++)
            ans = ans * 2 % MOD;
        printf("%d",(ans - 1 - n - n * (n - 1) / 2 + MOD) % MOD);
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 2)
            ans = (ans + dp[k[i]]) % MOD;
        sum += k[i];
        if (i == 1)
            for (int j = sum - 1; j >= 0; j--)
                dp[j] = 1;
        else
            for (int j = sum - 1; j >= 0; j--)
                dp[j] = (dp[j] + (j >= k[i] ? dp[j - k[i]] : t)) % MOD;
        t = t * 2 % MOD;
    }
    printf("%d",ans);
    return 0;
}
