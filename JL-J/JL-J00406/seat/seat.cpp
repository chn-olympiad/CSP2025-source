#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","u"stdout);

    int b = 0,c = 1,a[100],n,m,l = 0,h = 1,f = 0;
    cin >> n >> m;
    for(int i = 0;i < n * m;i++)
    {
        cin >> a[i];
    }
    b = a[0];
    for(int i = 0;i < n * m;i++)
    {
        if(b < a[i])
        {
            c++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        if(c < n * i)
        {
            l = i;
            break;
        }
    }

    for(int i = 1;i <= m;i++)
    {
        if(c = n * i)
        {
            l = i;
            break;
        }
    }
    f = c - (l - 1) * n;
    if(l % 2 == 1)
    {
        h = f;
    }
    else
    {
        h = n - f;
    }
    cout << l << " " << h;
    return 0;
}
