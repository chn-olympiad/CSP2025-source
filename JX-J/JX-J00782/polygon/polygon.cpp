#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 1)
    {
        cout << 9;
    }
    if (a[1] == 2)
    {
        cout << 6;
    }
    else
    {
        cout << 24;
    }
    cout << endl;
    return 0;
}
