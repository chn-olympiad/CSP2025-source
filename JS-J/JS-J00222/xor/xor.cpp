#include <bits/stdc++.h>
using namespace std;

int a[500008], n, k, f = 1, ans = 0;
void solve1()
{
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) ans++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) ans++;
            else
            {
                int t = i;
                while (a[i] == 1 && i < n) i++;
                if (i != n) ans += (i - t) / 2 + 1;
                else
                {
                    if (a[n] == 1) ans += (n + 1 - t) / 2;
                    else ans += (i - t) / 2 + 1;
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= 2) f = 0;
    }
    if (f == 1) solve1();
    return 0;
}
