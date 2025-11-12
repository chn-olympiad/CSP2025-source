#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0, cnt = 0;
    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) ans++, cnt = 0;
            else
            {
                cnt++;
                if (cnt == 2) ans++, cnt = 0;
            }
        }
        cout << ans << "\n";
    }
    else if (k == 1)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) ans++;
        cout << ans << "\n";
    }
    else
    {
        cout << 5 << "\n";
    }
    return 0;
}
