#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],now,pos,here;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> a[++pos];
            if (pos==1)
            {
                now=a[pos];
            }
        }
    }
    sort(a+1,a+pos+1);
    reverse(a+1,a+pos+1);
    for (int i=1;i<=pos;i++)
    {
        if (a[i]==now)
        {
            here=i;
        }
    }
    int c=(here-1)/n+1;
    int r=0;
    if (c%2==1)
    {
        r=here%n;
        if(r==0)
        {
            r=n;
        }
    }
    else
    {
        r=n-here%n+1;
        if (r==n+1)
        {
            r=1;
        }
    }
    cout << c << " " << r;
    return 0;
}
