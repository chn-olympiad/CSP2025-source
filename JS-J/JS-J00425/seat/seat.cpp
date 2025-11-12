#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int a[105], cnt[105], ans=1;
int i, j, k;
int X1, X2, X3, X4, X5;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (i = 1; i <= n*m; i++)
    {
        cin >> a[i];
    }
    x = a[1];
    for (j = 1; j <= n*m; j++)
    {
        cnt[a[j]]++;
    }
    for (k = 100; k >= 0; k--)
    {
        if (cnt[k] == 1)
        {
            if (x == k)
            {
                break;
            }
            ans++;
        }
    }
    X1 = (ans-1) % (2*n) + 1;
    X2 = (ans - X1) / n;
    if (X1 <= n)
    {
        X3 = X2+1;
        X4 = X1;
    }
    else if (X1 >= n+1)
    {
        X3 = X2+2;
        X4 = 2*n-X1+1;
    }
    cout << X3 << " " << X4 << endl;
    return 0;
}
