#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+10;
int n;
int a[MAXN];
int num[MAXN];
int ans=0;
int dfs(int dep,int w)
{
    if(dep==w)
    {
        int sum=0;
        int x=0;
        for(int i=1;i<=w-1;i++)
        {
            sum+=a[num[i]];
        }
        for(int i=num[dep-1]+1;i<=n;i++)
        {
            if(a[i]<sum)
            {
                x=(x+1)%998244353;
            }
        }
        return x;
    }
    else
    {
        int x=0;
        for(int i=num[dep-1]+1;i<=n;i++)
        {
            num[dep]=i;
            x=(x+dfs(dep+1,w))%998244353;
        }
        return x;
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        ans=(ans+dfs(1,i))%998244353;
    }
    cout<<ans<<'\n';
    return 0;
}
