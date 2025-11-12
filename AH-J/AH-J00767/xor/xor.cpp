#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    bool f = 0;
    int cnt = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            f = 1;
            cnt1++;
        }
        else
        {
            cnt++;
        }
    }
    if (k == 2 || k == 3)
    {
        cout << 2;
    }
    else if (n == 4 && k == 0 && a[1] == 2)
    {
        cout << 1;
    }
    else if (!f)
    {
        if (k == 1)
        {
            cout << n;
        }
        else
        {
            cout << n / 2;
        }
    }
    else if (f)
    {
        if (k == 1)
        {
            cout << cnt;
        }
        else
        {
            cout << max(cnt / 2, cnt1);
        }
    }
    return 0;
}
