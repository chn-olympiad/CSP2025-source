#include <bits/stdc++.h>
using namespace std;
long n, k, a[(long)(5e5+3)], sum, ans, before[(long)(5e5+3)], used[(long)(5e5+3)];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%ld %ld", &n, &k);
    for (long i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j+i < n; j++)
        {
            if (before[j] == -1)
            {
                continue;
            }
            if (used[j+i])
            {
                before[j] = -1;
                continue;
            }
            sum = a[j+i] ^ before[j];
            if (sum == k)
            {
                ans++;
                for (long k = j-i; k <= j+i; k++)
                    before[k] = -1;
                for (long k = j; k <= j+i; k++)
                    used[k] = 1;
            }
            else
                before[j] = sum;
        }
    }
    printf("%ld", ans);
    return 0;
}
