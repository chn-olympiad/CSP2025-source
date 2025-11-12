#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,h,l;
int main()
{
    freopen('seat.in','r',stdin);
    freopen('seat.out','w',stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m;i++)
    {
        cin >> a[i];
    }
    x = a[1];
    sort(a+1,a+n*m+1);
    for (int i = 1; i <= n*m; i++)
    {
        if (a[i] == x)
        {
            y = i;
        }
    }
    if (y/n%2 == 0 && y%n == 0)
    {
        l = y/n;
        h = 1;
    }
    else if (y%n == 0 && y/n%2==1)
    {
        l = y/n;
        h = n;
    }
    else if (y/n%2 == 1)
    {
        l = y/n+1;
        h = y - (y%n*2-1);
    }
    else if (y/n%2 == 0)
    {
        l = y/n+1;
        h = y-(y/n*n);
    }
    cout << l << h;
}
