#include <bits/stdc++.h>

using namespace std;
int a[110];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) cin >> a[i];
    int x = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= n * m; ++i)
    {
        if (a[i] == x)
        {
            int y = i / n + (i % n != 0);
            int z = i % n;
            if (!z) z = n;
            cout << y << " ";
            if (y % 2 == 0) z = m - z + 1;
            cout << z << endl;
            return 0;
        }
    }
    return 0;
}
