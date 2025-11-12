#include <bits/stdc++.h>
using namespace std;
int c,r,n,m,s=1,a[110];
int main()
{
    freopen('seat.in','r',stdin);
    freopen('seat.out','w',stdout);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> a[i];
        if (a[1]<a[i])
        {
            s++;
        }
    }
    c=(s-s%n)/n+1;
    if (s%n==0)
    {
        c--;
    }
    if (((s-s%n)/n)%2==0)
    {
        r=s%n;
        if (r==0)
        {
            r=n;
        }
    }
    else
    {
        r=n-s%n+1;
        if (s%n==0)
        {
            r--;
        }
    }
    cout << c << r;
    return 0;
}
