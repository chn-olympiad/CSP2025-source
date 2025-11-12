#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105][105],n,m,x[10005];
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> x[i];
    }
    int r = a[1];
    for (int i=1;i<=n*m;i++)
    {
        if(x[i]<x[i+1])
        {
            int b = x[i];
            x[i] = x[i+1];
            x[i+1] = b;
        }
    }
    for (int i=1;i==n*m;i++)
    {
        if(c[i] == r)
        {
            int c = x[i];
            break;
        }
    }
    if((c/n)%2 == 1)
    {
        cout << c/n << " " << m-(c/n);
    }
    else
    {
        cout << c/n << " " << (m*n-c)%m;
    }
}
