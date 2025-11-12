#include<bits/stdc++.h>
using namespace std;
int n,m,nx=1,mx=1,cnt=1,ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        nx=nx*i;
    }
    for(int i=1;i<=n;i++)
    {
        mx=mx*i;
    }
    for(int i=1;i<=n-m;i++)
    {
        cnt=cnt*i;
    }
    ans=nx/mx/cnt;
    ans=ans%998244353;
    cout<<ans;
    return 0;
}
