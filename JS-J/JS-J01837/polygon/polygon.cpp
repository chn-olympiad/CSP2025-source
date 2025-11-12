#include <bits/stdc++.h>
using namespace std;
unsigned long long n, a[5005], sum[5005];
const long long MOD = 998244353;
unsigned long long ans = 0;
bool check(int l, int r, int k, int q)
{
    if(r - l - q + k < 3)
    {
        return false;
    }
    if(sum[r] - sum[q] + sum[k - 1] - sum[l - 1] > a[r] * 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];

    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 2; j <= n; j ++)
        {
            if(check(i, j, 1, 0))
            {
                ans = (ans + 1) % MOD;
            }
            for (int k = i + 1; k <= j - 1; k ++)
            {
                for (int q = k; q <= j - 1; q ++)
                {
                    if(check(i, j, k, q))
                    {
                        ans = (ans + 1) % MOD;
                    }
                }
            }

        }
    }
    cout << ans;
    return 0;
}
