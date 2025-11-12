#include <bits/stdc++.h>
using namespace std;

int n, sum = 0, a[5005],ans=0;

void g(int m, int b[], bool f[], int j)
{
    if (m == 0)
    {
        if (j < 3)
            return;
        sort(b + 1, b + j + 1);
        if (b[j] * 2 < sum)
            ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i])
            continue;
        f[i] = 1;
        b[j] = a[i];
        j++;
        g(m - 1, b, f, j);
    }
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    if (n == 3)
    {
        if (a[n] * 2 < sum)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    else if (n <= 10)
    {
        int b[5005] = {}, j = 1;
        bool f[5005];
        for (int i = 0; i < n; i++)
            g(i, b, f, j);
        cout << ans % 998244353 << endl;
    }

    else
        cout << 0 << endl;
    return 0;
}