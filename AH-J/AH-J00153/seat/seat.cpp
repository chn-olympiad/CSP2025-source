#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int x = 0;
    cin >> n ;
    cin >> m;
    int a[n*m+1];
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int s = a[1];
    sort(a+1,a+n*m+1);
    for (int i = n*m;i >= 1;i--)
    {
        if (a[i] == s)
        {
            x = n * m - i + 1;
            break;
        }
    }
    if (x % n == 0)
    {
        cout << x / n << " ";
        if (x / n  % 2 == 0)
        {
            cout << "1";
        }
        else
        {
            cout << m;
        }
    }
    else
    {
        cout << x / n +1 << " ";
        if (x / n % 2 == 0)
        {
            cout << x % n;
        }
        else
        {
            cout << m - x % n + 1;
        }
    }
    return 0;
}
