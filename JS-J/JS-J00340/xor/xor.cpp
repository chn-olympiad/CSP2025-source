#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], sum;
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    bool fa = 1, fb = 1, fc = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] != 1)
            fa = 0;
        if (a[i] != 0 && a[i] != 1)
            fb = 0;
        if (a[i] > 255)
            fc = 0;
    }
    if (fa)
    {
        cout << n / 2;
        return 0;
    }
    if (fb)
    {
        if (k)
            cout << sum;
        else
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] == a[i + 1])
                    cnt++, i++;
            cout << cnt;
        }
        return 0;
    }
    return 0;
}
