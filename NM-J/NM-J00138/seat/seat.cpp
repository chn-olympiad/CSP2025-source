#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, a[105], a1, num;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    a1 = a[1];
    sort(a + 1, a + 1 + n * m);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == a1)
        {
            num = i;
        }
    }
    num = n * m - num + 1;
    int l = num / n, h = num % n;
    if (h == 0)
    {
        if (l % 2 == 1)
            cout << l << " " << n;
        else
            cout << l << " " << 1;
    }else
    {
        if ((l + 1) % 2 == 1)
            cout << l + 1 << " " << h;
        else
            cout << l + 1 << " " << n - h + 1;
    }
    return 0;
}
