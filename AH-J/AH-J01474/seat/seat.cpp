#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[12][12],d[105],b=0,c=0;
    cin>>b>>c;
    for (int i=1;i<=(b*c);i++)
    {
        cin>>d[i];
    }
    int g=d[1];
    for (int i=1;i<=b*c;i++)
    {
        for (int j=i+1;j<=b*c;j++)
        {
            if (d[i]<=d[j])
            {
                int e=d[i];
                d[i]=d[j];
                d[j]=e;
            }
        }
    }
    int f=1;
    for (int i=1;i<=c;i++)
    {
        if (i%2==1)
        {
            for (int j=1;j<=b;j++)
            {
                a[i][j]=d[f];
                f+=1;
            }
        }
        if (i%2==0)
        {
            for (int j=b;j>=1;j--)
            {
                a[i][j]=d[f];
                f+=1;
            }
        }
    }
    for (int i=1;i<=c;i++)
    {
        for (int j=1;j<=b;j++)
        {
            if (a[i][j]==g)
            {
                cout<<i<<" "<<j;
            }
        }
    }

    return 0;
}
