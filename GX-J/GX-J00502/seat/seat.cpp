#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,bm = 1;
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin >>n >>m;
    cin >> a[1];
    x = a[1];
    for (int i = 2; i <= n * m; i++)
    {
        cin >> a[i];
        if(x < a[i])
        {
            bm++;
        }
    }
    int x = bm / n;
    int y = bm % n;
    if(y == 0)
    {
        y = n;
    }
    else
    {
        x+=1;
    }
    if(x % 2 == 0)
    {
        y = n - y+1;
    }
    cout<< x <<" " << y;
    return 0;
}
