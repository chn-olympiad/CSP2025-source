#include <bits/stdc++.h>
using namespace std;
int n, a[5], b[15][15][15];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 10; k++)
            {
                int sum = i + j + k;
                int maxn = max(max(i, j), k);
                if (sum > maxn * 2)
                    b[i][j][k] = 1;
            }
    cout << b[a[1]][a[2]][a[3]];
    return 0;
}
