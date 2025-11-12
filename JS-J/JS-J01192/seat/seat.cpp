#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[110];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int r, R = a[1];
    sort(a + 1, a + n * m + 1);
    for (int i = n * m; i >= 1; i--)
    {
        if (a[i] == R) r = n * m - i + 1;
    }
    int c = r / n + (r % n != 0);
    r %= n;
    if (r == 0) r = n;
    if (c % 2 == 0) r = n - r + 1;
    cout << c << " " << r;
    return 0;
}
