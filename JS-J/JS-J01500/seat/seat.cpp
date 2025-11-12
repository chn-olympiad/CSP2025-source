#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n, m, a[N], sc, id;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    sc = a[1];
    sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; i++)
        if (a[i] == sc)
        {
            id = n * m - i + 1;
            break;
        }
    int c = id / n + (id % n != 0);
    int r = (c % 2 == 1 ? (id % n == 0 ? n : id % n) : n - (id % n == 0 ? n : id % n) + 1);
    cout << c << ' ' << r;
    return 0;
}
