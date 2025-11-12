#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int t = a[1], tmp;
    sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; i++)
    {
        if (t == a[i])
        {
            tmp = i;
            break;
        }
    }
    int wz = n * m + 1 - tmp;
    int x, y;
    if (wz % n == 0)
    {
        x = wz / n;
        y = n;
    }
    else
    {
        x = wz / n + 1;
        y = wz % n;
    }
    if (x % 2 == 0)
    {
        y = n + 1 - y;
    }
    cout << x << " " << y << endl;
    return 0;
}
// 100pts
