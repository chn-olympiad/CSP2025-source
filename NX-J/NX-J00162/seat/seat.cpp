#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mb,xb;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    mb = a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i = 1;i <= n*m;i++)
    {
        if(a[i] == mb)
        {
            xb = i;
        }
    }
    int l = ceil(1.0* xb / n);
    cout << l << ' ';
    if(l % 2 == 0)
    {
        if(xb % n == 0)
        {
            cout << 1;
        }
        else
        {
            cout << n-xb%n+1;
        }
    }
    else
    {
        if(xb % n == 0)
        {
            cout << n;
        }
        else
        {
            cout << xb%n;
        }
    }
}
