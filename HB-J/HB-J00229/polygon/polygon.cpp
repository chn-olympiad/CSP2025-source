#include<bits/stdc++.h>
using namespace std;
const int mx=5500;
int n,a[mx],i,ans=0;
int pax(int px)
{
    int i,x,allx,mxa;
    for(i=3;i<=n;i++)
    {
        for(x=px;x<=px+i;x++)
        {
        allx+=a[x];
        mxa=max(mxa,a[x]);
        }
        if(allx>=(mxa*2))ans++;
    }
    if(px<=n)pax(px+1);
    else return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    cout<<pax(1)/2;
    return 0;
}

