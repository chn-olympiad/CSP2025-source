#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,x,num;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    for (int i=1;i<=n*m;i++)
    {
        for (int j=i;j<=n*m;j++)
        {
            if (a[i]<a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==x)
        {
            num=i;
            break;
        }
    }
    if (num%n==0)
    {
        c=num/n;
        if (c%2==0)
        {
            r=1;
        }
        if (c%2==1)
        {
            r=n;
        }
    }
    else
    {
        c=num/n;
        c++;
        if (c%2==0)
        {
            r=n-num%n+1;
        }
        if (c%2==1)
        {
            r=num%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
