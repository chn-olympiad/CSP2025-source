#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], a1, kaituo;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n*m; i++)
    {
        cin >> a[i];
    }
    a1 = a[1];
    sort(a, a+n*m+1, cmp);
    for(int i=1; i<=n*m; i++)
    {
        if(a[i]==a1)
        {
            kaituo = i;
            break;
        }
    }
    int x=kaituo/n+1, y=kaituo%n;
    cout << x << ' ';
    if(x%2)
    {
        if(y)
        {
            cout << n-y+1;
        }
        else
        {
            cout << 1;
        }
    }
    else
    {
        if(y)
        {
            cout << y;
        }
        else
        {
            cout << n;
        }
    }
    return 0;
}
