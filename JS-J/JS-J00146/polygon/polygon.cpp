#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] == 1)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int ans2 = 1;
            for (int j = n; j >= n - i + 1; j--)
            {
                ans2 *= j;
            }
            ans += ans2;
        }
        cout << ans % 998244353 << endl;
    }
    else if (n == 3)
    {
        if (a[0] + a[1] > a[2])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}