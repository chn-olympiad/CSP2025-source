#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int R;
    cin >> R;
    int a[n * m];
    for (int i = 0; i < n * m - 1; i++)
        cin >> a[i];
    sort(a, a + n * m - 1, greater<int> ());
    int pos = upper_bound(a, a + n * m - 1, R, greater<int> ()) - a;
    int l = ceil(double(pos + 1) / n);
    int h;
    if (l % 2 == 1)
        h = pos % n + 1;
    else if (l % 2 == 0)
        h = n - pos % n;
    cout << l << ' ' << h;
    return 0;
}
