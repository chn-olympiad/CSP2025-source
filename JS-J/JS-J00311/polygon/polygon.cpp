#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000008],v[1000008];
int p=958244353,ans,n;
bool check(int mx,int sum,int dep)
{
    return mx*2<sum&&dep>=3;
}
void dfs(int dep,int mx,int sum,int pre)
{
    if(check(mx,sum,dep)) ans=(ans+1)%p;
    for(int i=pre;i<=n;i++)
    {
        dfs(dep+1,max(mx,a[i]),sum+a[i],i+1);
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,-0x3f3f3f3f,0,1);
    cout<<ans;
    return 0;
}
