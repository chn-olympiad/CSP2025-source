#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int srch(int target)
{
    int l = 1;
    int r = n * m;
    int mid = (l + r) >> 1;
    while (true)
    {
        if (a[mid] > target)
        {
            l = mid + 1;
        }
        else if (a[mid] < target)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
        if (a[mid + 1] == target) return mid + 1;
        if (a[mid - 1] == target) return mid - 1;
        mid = (l + r) >> 1;
    }
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int tg = a[1];
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    int idx = srch(tg);
    int x, y;
    x = (idx - 1) / n + 1;
    cout << x;
    if (x % 2 == 1)
    {
        if (idx % n)
        {
            y = idx % n;
        }
        else
        {
            y = n;
        }
    }
    else
    {
        if (idx % n)
        {
            y = idx % n;
        }
        else
        {
            y = n;
        }
        y = (n + 1) - y;
    }
    cout << " " << y << endl;
    return 0;
}
