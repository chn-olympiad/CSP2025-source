#include <bits/stdc++.h>
using namespace std;
int a[225],h[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,b;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[i+1])
        {
            swap(a[i],a[i+1]);
        }
    }
    for(int f=1;f<=n*m;f++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                h[i][j]=a[f];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(h[i][j]==b)
            {
                c=i;
                r=j;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
