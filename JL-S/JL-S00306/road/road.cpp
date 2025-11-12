#include<bits/stdc++.h>
using namespace std;
struct node
{
    int to,val;
};
vector<node>g[10005];
map<int,int> mp;
int ans=INT_MAX;
int n,m,k;
void dfs(int u,int fa,int sum,int num)
{
    if(num==n)
    {
        ans=min(ans,sum);
        return;
    }
    for(auto x:g[u])
    {
        int v=x.to,w=x.val;
        if(v==fa)continue;
        if(mp[v])continue;
        mp[v]=1;
        dfs(v,u,sum+w,num+1);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
    {
        mp.clear();
        dfs(i,0,0,1);
    }
    printf("%d",ans);
}
