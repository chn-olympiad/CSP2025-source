#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],c,r,q;
bool x(int g1,int g2)
    {
        return g1>g2;
    }
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    q=a[1];
    sort(a+1,a+n*m+1,x);
    for(int i=1;i<=n*m;i++)
    {
        if(q==a[i])
        {
            q=i;
            break;
        }
    }
    c=(q-1)/n+1;
    if(c%2==1)
    {
        r=q-(c-1)*n;
    }
    else
    {
        if(c%2==0)
        {
            r=n+1-(q-(c-1)*n);
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
