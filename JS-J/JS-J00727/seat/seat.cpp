#include <bits/stdc++.h>
using namespace std;
struct xd{
    int s,num;
}a[105];
bool cmp(xd x,xd y)
{
    return x.s>y.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int xdn=n*m;
    for(int i=1;i<=xdn;i++)
    {
        cin>>a[i].s;
        a[i].num=i;
    }
    sort(a+1,a+xdn+1,cmp);
    int x=0;
    for(int i=1;i<=xdn;i++)
    {
        if(a[i].num==1)
        {
            x=i;
            break;
        }
    }
    int d=(x-1)/n;
    int dn=x%(n);
    cout<<d+1<<" ";
    if(d%2==0)
    {
        if(dn==0) cout<<n;
        else cout<<dn;
    }
    else{
        if(dn==0) cout<<1;
        else cout<<n-dn+1;
    }
    return 0;
}