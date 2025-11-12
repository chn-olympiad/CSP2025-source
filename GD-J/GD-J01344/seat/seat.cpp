#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a1, x, gt1 = 0;
    cin >> n >> m >> a1;
    m = n * m - 1;
    while (m--)
        cin >> x, gt1 += x > a1;
    div_t dv = div(gt1, n);
    cout << dv.quot + 1 << ' ' << ((dv.quot & 1) ? n - dv.rem : dv.rem + 1);
    return 0;
}
