#include<bits/stdc++.h>
using namespace std;
int n,m,rscore,rp,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+5];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    rscore=a[1];
    std::sort(a+0,a+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==rscore)  rp=n*m-i+1;
    }
    if(rp%m==0)  c=rp/m;
    else
    {
        c=rp/m+1;
    }
    if(c%2==0)
    {
        r=n-rp%n+1;
    }
    else
    {
        if(rp%m==0)  r=n;
        else r=rp%m;
    }
    cout<<c<<' '<<r;
    return 0;
}
