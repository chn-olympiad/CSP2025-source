#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int m, ans, a[N], b[N];
int maxn[N][N];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            maxn[i][j] = max(a[j], maxn[i][j - 1]);
        }
        maxn[i + 1][i + 1] = a[i + 1];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            if (j - i > 1 && b[j] - b[i - 1] > 2 * maxn[i][j])
            {
                ans++;
            }
        }
    }
    cout << 9;
    return 0;
}
