#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x > y;
}

int m,n,x,t,c,r;
int a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
        cin >> a[i];
    x = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for (int i = 1;i <= n * m;i++)
    {
        if (a[i] == x)
        {
            t = i;
            break;
        }
    }
    if (t % n == 0)
    {
        c = t / n;
        if (c % 2 == 1)
            r = n;
        else
            r = 1;
    }
    else
    {
        c = t / n + 1;
        if (c % 2 == 1)
            r = t % n;
        else
            r = n - t % n + 1;
    }
    cout << c << " " << r;
    return 0;
}
