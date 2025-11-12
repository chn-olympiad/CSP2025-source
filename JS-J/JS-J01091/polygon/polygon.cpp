#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[5005], s[5005], N = 9998244353;

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 4; i <= n; i++)
    {
        int jc1 = 1, jc2 = 1;
        for (int j = i - 1; j >= 3; j--)
            jc1 *= j;
        for (int j = 2; j <= i - 3; j++)
            jc2 *= j;
        jc1 /= jc2;
        ans = (ans + jc1) % N;
    }
    cout << ans << "\n";
    return 0;
}
