#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], ans;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= (n - 2); i++)
    {
        for (int j = i + 1; j <= (n - 1); j++)
        {
            int sum = (a[i] + a[j]);
            for (int k = j + 1; k <= n; k++)
            {
                if (sum + a[k] > a[k] * 2)
                    ans++;
            }
        }
    }
    cout << ans % mod;
    return 0;
}
