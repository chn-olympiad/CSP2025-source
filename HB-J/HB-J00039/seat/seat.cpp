#include <bits/stdc++.h>
using namespace std;
int n,m,rs,l,c,r;
int a[105],b[105],d[105];
int main()
{
    freopen(seat.in,"r",stdin);
    freopen(seat.out,"w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    rs=a[1];
    for(int i=1;i<=m*n;i++)
    {
        b[a[i]]=1;
    }
    int x=1;
    for(int i=100;i>=1;i--)
    {

        if(b[i]==1)
        {
            d[x]=i;
            x++;
        }
    }

    for(int i=1;i<=m*n;i++)
    {
        if(d[i]==rs)
            l=i;
    }
    c=l/m;
    r=l%m;
    if(r==0)
        r=m;
    else
        c+=1;
    cout << c << " " << r;
    return 0;
}
