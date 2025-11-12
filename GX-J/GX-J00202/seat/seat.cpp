#include <bits/stdc++.h>
using namespace std;
int a[150];
int n,m,z,o;
int main()
{
    freopen("seat.in,"r",stdin);
    freopen("seat.out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    for (int i=1;i<=n*m;i++)
    {
        for (int j=1;j<=n*m;j++)
        {
            if (a[j]<a[j+1])
            {
                int zz;
                zz=a[j];
                a[j]=a[j+1];
                a[j+1]=zz;
            }
        }
    }
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==x)
        {
            z=i;
            break;
        }
    }
    while (z>=m)
    {
        z-=m;
        o++;
    }
    cout<<z+1<<" "<<o+1;
    return 0;
}

