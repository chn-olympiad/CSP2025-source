#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,c,r,l,x;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[i-1])
        {
            x=a[i];
            a[i]=a[i-1];
            a[i-1]=x;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]=t)
        {
            l=i;
        }
    }
    c=l%n+1;
    r=l/m;
    if(c%2==0)
    {
        r=n-r;
    }
    cout<<c<<' '<<r;
    return 0;
}
