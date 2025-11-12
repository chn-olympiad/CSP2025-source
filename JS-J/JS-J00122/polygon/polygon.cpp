#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, ans;
int a[N];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (long long i = 1; i <= 1 << n; ++i)
    {
        int sum = 0, maxn = 0;
        for (long long j = 0; j < n; ++j)
        {
            if ((i >> j) & 1LL)
            {
                sum += a[j + 1];
                maxn = max(maxn, a[j + 1]);
            }
        }
        if (sum > 2 * maxn) ans = (ans + 1) % 998244353;
    }
    cout << ans << "\n";

    return 0;
}