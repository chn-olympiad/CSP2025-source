#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[105];

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, cnt = 0, sc, c, r;
    cin >> n >> m;
    cin >> sc;
    a[1] = sc;
    for (int i = 2; i <= n * m; i++)
    {
        cin >> a[i];
        if (a[i] > sc) cnt++;
    }
    c = cnt / n + 1;
    if (c % 2) r = cnt % n + 1;
    else r = n - cnt % n;
    cout << c << " " << r << '\n';
    return 0;
}