#include<bits/stdc++.h>
using namespace std;
int n,m,s,x,p,c,r,h;
int a[10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+s+1);
    for(int i=s;i>=1;i--)
    {
        h++;
        if(x==a[i])
        {
            p=h;
        }
    }
    if(p%n==0)
    {
        c=p/n;
    }
    else
    {
        c=p/n+1;
    }
    if(c%2==1)
    {
        r=p%n;
        if(p%n==0) r=n;
    }
    else
    {
        r=n-p%n+1;
        if(p%n==0) r=1;
    }
    cout<<c<<" "<<r;
    return 0;
}
