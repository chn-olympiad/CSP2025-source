#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],f,i,j,u,x,y;
int o;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    f=a[0];
    for(i=0;i<n*m-1;i++)
    {
        for(j=i+1;j<n*m;j++)
        {
            if(a[i]<a[j])
              swap(a[i],a[j]);
        }
    }
    for(i=0;i<n*m;i++)
    {
        if(f==a[i])
        {
            u=i;
            break;
        }
    }
    u++;
    x=u/n+1;
    y=u%n;
    if(y==0)
    {
        y=n;
        x--;
    }
    o=x%2;
    if(o==0)
        y=n+1-y;
    cout<<x<<" "<<y;
    return 0;
}
