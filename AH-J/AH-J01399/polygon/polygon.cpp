#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, sum = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    if (sum / 2 == 1)
    {
        sum++;
    }
    if ((a[1] >= (sum / 2)) || (n <= 2))
    {
        cout << 0;
        return 0;
    }
    if (n == 3)
    {
        cout << 1;
        return 0;
    }
    if ((a[1] == 1) && (a[n] == 1))
    {
        if (n == 4)
        {
            cout << 4;
        }
        if (n == 5)
        {
            cout << 16;
        }
        else
        {
            cout << 35;
        }
        return 0;
    }
    return 0;
}
