#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int t = 0;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    t = a[1];
    int id = 0;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == t) id = i;
    }
    if (id % n == 0)
    {
        if ((id / n) % 2 != 0)
        {
            cout << id / n << " " << n;
        }
        else
        {
            cout << id / n << " " << "1";
        }
    }
    if (id % n != 0)
    {
        if ((id / n + 1) % 2 == 0)
        {
            cout << id / n + 1 << " " << n - (id % n) + 1;
        }
        else
        {
            cout << id / n + 1 << " " << id % n;
        }
    }
    return 0;
}
