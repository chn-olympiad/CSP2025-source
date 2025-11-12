#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[103],r,ans = 1;
    cin >> m >> n >> r;
    for(int i = 1;i <= n * m - 1;i++)
    {
        cin >> a[i];
        if(a[i] > r)
        {
            ans++;
        }
    }
    int x,y;
    if (ans % m == 0)
    {
        x = ans/m;
        if((ans / m) % 2 == 0) y = 1;
        else if ((ans / n) % 2 == 1) y = n;
    }
    else
    {
        x = ans / m + 1;
        if (x % 2 == 0)
        {
            y = m + 1 -(ans % m);
        }
         else if (x % 2 == 1)
        {
            y = ans % m;
        }
    }
    cout << x  << " " << y;
    return 0;
}
