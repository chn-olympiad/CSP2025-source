#include <bits/stdc++.h>
using namespace std;
int n, ans = -INT_MAX, cnt = 0;
int a[5005];
int main()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
       if (a[i] > ans)
       {
           ans = a[i];
       }
       cnt += a[i];
    }
    if (cnt > ans * 2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    cout << '\n';
    return 0;
    //HEI YAN FEN SHEN, ZI WEI KE MIAO?
}
