#include <bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long n,k,ans,a[N],b[N];
bool vis[N];
void dfs(int u,long long sum)
{
    if(u>n)
    {
        ans=max(ans,sum);
        return ;
    }
    if(u==n)
    {
        if(!vis[u]&&a[u]==k) ans=max(ans,sum+1);
        else ans=max(ans,sum);
        return ;
    }
    if(b[u]!=0)
    {
        vis[u]=true;
        vis[b[u]]=true;
        dfs(b[u]+1,sum+1);
        vis[u]=false;
        vis[b[u]]=false;
    }
    else dfs(u+1,sum);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        b[i]=0;
    }
    for(int i=1;i<n;++i)
    {
        long long sum=a[i];
        if(sum==k)
        {
            b[i]=i;
            continue;
        }
        int j=i+1;
        while(sum!=k&&j<=n)
        {
            sum=sum^a[j];
            j++;
        }
        if(sum==k)
        {
            b[i]=j-1;
        }
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
