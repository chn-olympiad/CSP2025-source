#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[105],n,m,k;
    cin >> n >> m;
    for(int i = 1;i <= 10;i++)
        a[i] = 0;
    cin >> k;
    for(int i = 1;i <= n*m;i++)
    {
        int h;
        cin >> h;
        a[h] = h;
    }
    a[k] = k;
    int p = 0;
    for(int i = 100;i > 0;i--)
    {
        p++;
        if(a[i] == k)
        {
            k = p;
            break;
        }
    }
    int y,r;
    if(p%n == 0)
    {
        y =p/n;
    }
    else
    {
        y = p/n+1;
    }
    if(y%2 ==0)
    {
        r = p%n+1;
    }
    else
    {
        r = p/n;
    }
    cout << y << r;
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 );
}
