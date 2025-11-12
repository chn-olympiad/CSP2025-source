#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "w", stdout);
    int n = 10000, m = 1000000, k = 10;
    cout << n << ' ' << m << ' ' << k << '\n';
    for (int i = 1; i < n; i++)
        cout << i << ' ' << i + 1 << " " << 1000000000 << '\n';
    mt19937 mt(time(0));
    uniform_int_distribution<int> d(1, n);
    for (int i = 1; i <= m - n + 1; i++)
        cout << d(mt) << ' ' << d(mt) << " " << d(mt) << '\n';
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            cout << d(mt) << ' ';
        cout << '\n';
    }
    return 0;
}