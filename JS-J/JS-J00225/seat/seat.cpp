#include <bits/stdc++.h>

using namespace std;
int n,m,a[103],x,y,cnt,pp,t=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[++cnt];
        }
    }
    pp=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    while(a[t]!=pp)
    {
        t++;
    }
    y=t/n;
    x=t%n;
    if(x!=0)y++;
    if(x==0)
    {
        if(y%2==0)
        {
            x=1;
        }else{
            x=n;
        }
    }
    if(x!=0)
    {
        if(y%2==0)
        {
            x=n-x+1;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
