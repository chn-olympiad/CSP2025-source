#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n, a[5001], ans;
bool check(int l, int r)
{
    int maxn = -INT_MAX, sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    if (r - l + 1 >= 3 && sum > maxn * 2)
        return true;
    return false;
}
int main()
{
    freopen("polygon.in", "r",  stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (check(i, j))
                ans++;
        }
    }
    printf("%d", ans % mod);
    return 0;
}
