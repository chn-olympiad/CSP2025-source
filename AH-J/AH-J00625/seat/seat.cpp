#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[150];
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) cin >> a[i];
    int flag = a[1];
    int seat = 0;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n *m; ++i)
    {
        if (a[i] == flag)
        {
            seat = i;
            break;
        }
    }
    int k1 = (seat - 1) / n, k2 = 0;
    if (k1 % 2 == 0)
    {
        k2 = seat - k1 * n;
    }else{
        k2 = m - (seat - k1 * n) + 1;
    }
    cout << k1 + 1<<" " << k2;
    return 0;
}
