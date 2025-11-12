#include<bits/stdc++.h>
using namespace std;
const int N=5009;
int a[N];
bool f[N];
bool b=false;
int n;
long long res=0;
void dfs(int ans,int maxs,int re)
{
    if(ans>maxs*2)
    {

        res=(res+1)%998244353;
    }
    for(int i=re+1;i<=n;i++)
    {
        if(!f[i])
        {
            f[i]=true;
            dfs(ans+a[i],max(a[i],maxs),i);
            f[i]=false;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            b=true;
        }
    }
    if(!b)
    {
        long long ans=0;
        for(int i=1;i<=n-2;i++)
        {
            ans=(ans+i)%998244353;
        }
        cout<<ans;
    }
    else
    {
        dfs(0,0,0);
        cout<<res;
    }
    return 0;
}
