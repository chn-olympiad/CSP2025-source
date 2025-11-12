#include <bits/stdc++.h>
using namespace std;
struct ks
{
    int h;
    int l;
    int f;
}c[100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,j,k=0,x,b,n,m;
    cin>>n>>m;
    for(i=1;i<=m;i+=2)
    {
        for(j=1;j<=n;++j)
        {
            c[k].l=i;
            c[k].h=j;
            k++;
        }
        k=k+n+1;
    }
    k=2;
    for(i=2;i<=m;i+=2)
    {
        for(j=n;j>=1;j--)
        {
            c[k].l=i;
            c[k].h=j;
            k++;
        }
        k=k+n+1;
    }
    for(i=0;i<n*m;++i)
    {
        cin>>c[i].f;
    }
    b=c[0].f;
    for(i=0;i<n*m-1;++i)
    {
        x=i;
        for(j=i+1;j<n*m;++j)
        {
            if(c[x].f<c[j].f)
            {
                x=j;
            }
        }
        if(x!=i)
        {
            swap((c[x].f),(c[i].f));
        }
    }
    for(i=0;i<m*n;++i)
    {
        if(c[i].f==b)
        {
            cout<<c[i].l<<" "<<c[i].h;
        }
    }
    return 0;
}
