#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, sum = 0, c, d;
    cin >> n >> m;
    int a[n * m + 5];
    cin >> a[1];
    for (int i = 2; i <= n * m; i++)
    {
        cin >> a[i];
        if (a[1] < a[i])
        {
            sum++;
        }
    }
    c = sum / n + 1;
    if (c % 2 == 0)
    {
        cout << c << " " << n - (sum % n);
    }
    else if (c % 2 == 1)
    {
        cout << c << " " << (sum % n) + 1;

    }
    return 0;
}
