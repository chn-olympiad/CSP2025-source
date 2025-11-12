#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, a[5005], mx = -1, cnt = 0, ans = 0, x = 2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        cnt += a[i];
    }
    if (mx == 1)
    {
        cnt = n * (n - 1);
        for (int i = 3; i < n; i++)
        {
            x *= i;
            cnt *= (n - (i - 1));
            ans += (cnt / x);
        }
        ans++;
        cout << ans % 998244353;
        return 0;
    }
    if (cnt > mx * 2)
    {
        cout << 1;
        return 0;
    }
    else if (cnt <= mx * 2)
    {
        cout << 0;
        return 0;
    }
    return 0;
}
