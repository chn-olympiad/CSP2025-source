#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int a[505];int n;
int c(int x,int y)
{
    y=min(y,n-y);
    if(y==0)
    {
        return 1;
    }
    int o=n,p=1;
    for(int i=2;i<=y;i++)
    {
        p*=i;
        o*=(n-i+1);
        p%=mod;
        o%=mod;
    }
    return o/p;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0,d=n,x=1;
    for(int i=3;i<=n;i++)
    {
        ans+=c(n,i);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
//happy halloween!
//I'm Kremlin897! luogu:1046158
