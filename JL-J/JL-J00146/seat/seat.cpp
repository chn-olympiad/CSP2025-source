#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],d,aa,dy,dd;
int cmp(int x,int y)
{
    return y<x;
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
    aa=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==aa)d=i;
    }
    dy=d%n;
    dd=d/n;
    if(dy==0)
    {
        if(dd%2==1)cout<<dd<<" "<<n;
        else cout<<dd<<" "<<1;
        return 0;
    }
    if(dd%2==1)cout<<dd+1<<" "<<n-dy+1;
    else cout<<dd+1<<" "<<dy;
    return 0;
}
