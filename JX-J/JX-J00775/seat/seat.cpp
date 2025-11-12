#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,xr,cup=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    xr=a[1];
    for(int i=1;i<n*m;i++)
    {
        if(a[i+1]>a[i])
        {
            cup=a[i];
            a[i]=a[i+1];
            a[i+1]=cup;
        }
    }
    for(int i=1;i<n*m;i++)
    {
     if(a[i]==xr)
        {
            xr=i;
            break;
        }
    }
    c=(xr+n-1)/n;
    if(c%2==1)
    {
        r=xr-(c-1)*n;
    }
    else
    {
        r=n+1-xr+(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}