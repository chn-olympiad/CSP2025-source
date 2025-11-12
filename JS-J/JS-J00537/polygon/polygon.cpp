#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e3 + 10, M = 1e4 + 10, MOD = 998244353;

int n;
int a[N];
int dp[N][M];
LL res = 0;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(dp, 0,sizeof dp);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        dp[a[i]][a[i]] = 1;
    }

    if (n < 3) {
        puts("0");
        return 0;
    }

    stable_sort(a + 1, a + n + 1);

    dp[0][0] = 1 ;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j < i; j ++ ) {
            for (int k = 0; k <= 10001; k ++ ) {
                dp[a[i]][min(k + a[i], 10001)] = (dp[a[i]][min(k + a[i], 10001)] + dp[a[j]][k]) % MOD;
            }
        }
    }

    for (int i = 3; i <= n; i ++) {
        for (int j = min(a[i] * 2 + 1, 10001); j <= 10001; j ++ ) {
            res = (res + dp[a[i]][j]) % MOD;
        }
    }

    printf("%lld\n", res);
    return 0;
}