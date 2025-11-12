#include <bits/stdc++.h>
using namespace std;
int a[100000];
int m,n;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int p = 1;
    for(int i = 1;i <= n*m;i++)
    {
        if(a[i] > a[1])
        {
            p++;
        }
    }
    int x = 0,y = 0;
    //x lie
    if(p > n && p%n != 0)
    {
        x = p/n+1;
    }
    if(p == n || p<n)
    {
        x = 1;
    }
    if(p > n && p%n == 0)
    {
        x = p/n;
    }
    //y hang
    if(p <= n)
    {
        y = p;
    }
    if(p > n && p%n == 0)
    {
        int q = p/n;
        if(q%2 == 1)
        {
            y = n;
        }
        if(q%2 == 0)
        {
            y = 1;
        }
    }
    if(p > n && p%n != 0)
    {
        int v = p/n+1;
        if(v%2 == 1)
        {
            y = p%n;
        }
        if(v%2 == 0)
        {
            int z = p/n;
            y = p-z*n;
        }
    }
    cout << x <<" " << y;
    return 0;
}
