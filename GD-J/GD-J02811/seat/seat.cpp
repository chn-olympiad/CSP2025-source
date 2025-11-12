# include <bits/stdc++.h>

using namespace std;

static const int N = 1e2 + 5;
int n, m, a[N * N], ans[N][N], cnt = 0, r;

int main ()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) { cin >> a[i]; }
    r = a[1];
    sort (a + 1, a + n * m + 1, greater <int> ());

    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[j][i] = a[++cnt];
            }
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                ans[j][i] = a[++cnt];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == r) 
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }

    return 0;
}