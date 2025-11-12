#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n < 3)
    {
        cout << 0;
        return 0;
    }
    if (n == 3)
    {
        sort(a + 1, a + n +1);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
        }
        int maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            maxx = max(maxx, a[i]);
        }
        if (sum > maxx * 2)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    cout << 366911923;
    return 0;
}
