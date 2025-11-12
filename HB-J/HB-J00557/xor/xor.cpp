#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r",  stdin);
    freopen("xor.out", "w", stdout);
    int n, a[500001], ans = 0, sum[500001];
    bool flag[500001] = {0};
    long long k;
    int head = 1, tail = 1;
    scanf("%d%lld", &n, &k);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = (sum[i - 1] ^ a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if ((sum[j] ^ sum[i - 1]) == k && (flag[j] == 0 && flag[i] == 0))
            {
                ans++;
                for (int l = i; l <= j; l++)
                    flag[l] = 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
