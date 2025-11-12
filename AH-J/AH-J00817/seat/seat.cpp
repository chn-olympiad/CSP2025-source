#include <bits/stdc++.h>
using namespace std;
int n, m, a, s = 1, t;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> a;
    for (int i = 1; i < n*m; i++)
    {
        cin >> t;
        if (a < t)
            s++;
    }
    int x, y;
    x = (s-1)/n+1;
    if (x%2)
        y = (s-1)%n+1;
    else
        y = n - (s-1)%n;
    cout << x << ' ' << y << endl;
    return 0;
}
