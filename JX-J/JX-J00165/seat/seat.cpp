#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m,s=0,o,c,d;
    cin >>n>>m;
    int x[n*m+5],a[n*m+5],b[n*m+5];
    for (int i=1;i<=n*m;i++)
    {

        cin >>x[i];
        b[i]=x[i];
    }
    for (int i=1;i<=n*m;i++)
    {
        for (int j=1;j<=n*m;j++)
        {
            if (s<x[j])
            {
                s=x[j];
            }
        }
        a[i]=s;
        for (int j=1;j<=n*m;j++)
        {
            if (x[j]==s)
            {
                x[j]=0;
            }
        }
        s=0;
    }
    for (int i=1;i<=n*m;i++)
    {
        if (b[1]==a[i])
        {
            o=i;
        }
    }
    for (int i=1;i<=m;i++)
    {
        if (o<=i*n)
        {

            c=i;
        }
    }
    if (o==2)
        c-=1;
    if (c%2==0)
    {
        d=n;
    }
    else
    {
        d=1+o%n;
    }
    if (o==2)
        d++;
    cout <<c<<" "<<d;
    return 0;
}
