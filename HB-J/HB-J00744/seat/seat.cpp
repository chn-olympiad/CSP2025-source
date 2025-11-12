#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,rp,rx,ry;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
        cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==r)
            rp=i;
    }
    if (((rp-1)/n)%2==0)
    {
        rx=(rp-1)/n+1;
        ry=rp-(rx-1)*n;
    }
    else
    {
        rx=(rp-1)/n+1;
        ry=n-(rp-(rx-1)*n)+1;
    }
    cout<<rx<<' '<<ry;
    return 0;
}
