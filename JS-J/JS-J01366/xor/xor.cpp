#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], x[1005], n, k;

int xdf(int wx, int wy)
{
    string x1, x2;
    while (wx)
    {
        x1 += (wx % 2 + 48);
        wx /= 2;
    }
    while (wy)
    {
        x2 += (wy % 2 + 48);
        wy /= 2;
    }
    string x3;
    for (int i = 0; i < max(x1.size(), x2.size()); i++)
    {
        if (x1[i] != x2[i]) x3 = "1" + x3;
        else x3 = "0" + x3;
    }
    int ans = 0;
    for (int i = 0; i < x3.size(); i++)
    {
        ans = ans * 2 + x3[i] - 48;
    }
    return ans;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        if (i > 1) s = (x[i] == x[i - 1]);
    }
    if (s)
    {
        if (k == 0) cout << n / 2;
        else if (k == 1) cout << n;
        else cout << 0;
        return 0;
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1e3; j >= 1; j--)
        {
            if (j == k)
            {
                a[i][j] = max(a[i - 1][j] + 1, a[i][j]);
            }
            else a[i][j] = max(a[i][xdf(x[i], j)], a[i][j]);
            maxn = max(maxn, a[i][j]);
        }
    }
    cout << a[n][k];
    return 0;
}
