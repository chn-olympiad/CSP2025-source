#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], dp[N];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, tmp, last = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        a[i] = a[i - 1] ^ tmp;
        for (int j = last + 1; j <= i; j++)
            dp[i] = max(dp[i], dp[j - 1] + ((a[j - 1] ^ a[i]) == k));
        if (dp[i] != dp[i - 1])
            last = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}