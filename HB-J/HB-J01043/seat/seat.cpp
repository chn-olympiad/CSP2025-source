#include <bits/stdc++.h>
using namespace std;

int n, m, b, sum = 1, x, y = 1, z;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> b;
    for (int i = 2; i <= n * m; i++)
    {
        int a;
        cin >> a;
        if (a > b)
            sum++;
    }
    if (sum % n == 0)
    {
        x = sum / n;
        z = n;
    }
    else
    {
        x = sum / n + 1;
        z = sum % n;
    }
    if (x % 2 == 1)
        y = 0 + z;
    else
        y = n - z + 1;
    cout << x << ' ' << y << endl;
    return 0;
}