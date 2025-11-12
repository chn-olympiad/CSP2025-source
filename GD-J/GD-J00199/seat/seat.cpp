#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e2 + 10;

int n, m;
int a[N], cnt;

signed main()
{
    if (1)
    {
        freopen("seat.in", "r", stdin);
        freopen("seat.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
    {
        cin >> a[i];
        cnt += a[i] >= a[1];
    }
    // cerr << "cnt = " << cnt << '\n';
    int y = (cnt - 1) / n + 1;
    int x = cnt - (y - 1) * n;
    if (y % 2 == 0)
    {
        x = n + 1 - x;
    }
    cout << y << ' ' << x << '\n';
}