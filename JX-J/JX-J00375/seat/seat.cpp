#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],t,r;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
        cin >> a[i];
    t = a[1];
    sort(a,a + n * m + 1);
    for (int i = 1;i <= n * m; i++)
    {
        if (a[i] == t)
        {
            r = i;
            break;
        }
    }
    cout << n * m / (n * m - r) << " " << n * m % (n * m - r) - n;
    return 0;
}
