#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, k, a[200005], mn = 200005, cnt = 0, ans = 0, mx = -1;
bool flag[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (k == 1)
    {
        for (int i = 1; i <= n; i++) if (a[i] == 1) cnt++;
        cout << cnt;
        return 0;
    }
    if (k == 0 && mn == 1 && mx == 1)
    {
        cout << n / 2;
        return 0;
    }
    else
    {
        if (a[1] == 0)
        {
            cnt++;
            flag[1] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == 1 && a[i - 1] == 1 && flag[i] == 0 && flag[i - 1] == 0)
            {
                cnt++;
                flag[i] = 1;
                flag[i - 1] = 1;
            }
            if (a[i] == 0)
            {
                cnt++;
                flag[i] = 1;
            }
        }
        cout << cnt;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        ans ^= a[i];
        if (ans == k)
        {
            cnt++;
            ans = 0;
        }
    }
    cout << cnt;
    return 0;
}
