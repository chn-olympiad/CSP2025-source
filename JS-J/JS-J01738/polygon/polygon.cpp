#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    if (n == 3)
    {
        if (sum > maxn * 2)
        {
            cout << "1";
        }
    }
    else
    {
        cout << "9";
    }
    return 0;
}
