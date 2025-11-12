#include <bits/stdc++.h>
using namespace std;

int n,m,rs,p,x,y,a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m >> rs;
    a[1] = rs;
    for(int i = 2;i <= n*m;i++)
        cin >> a[i];
    sort(a+1,a+n*m+1);
    for(int i = 1;i <= n*m;i++)
        if(a[i] == rs)
            p = n*m-i+1;
    if(p%n == 0)
    {
        y = p/n;
        if(y%2 == 0)
            x = 1;
        else
            x = n;
    }
    else
    {
        y = p/n+1;
        if(y%2 == 0)
            x = n-p%n+1;
        else
            x = p%n;
    }
    cout << y << " " << x;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
