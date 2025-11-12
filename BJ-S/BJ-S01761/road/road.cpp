#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
};
int n,m,k,buildv,sum,c[100020],a[50],dis[100020];
long long usem,ans=1e18;
vector<node>G[10020];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
bool dfs(int x,int fa)
{
    //cout<<x<<"#"<<usem<<endl;
    if(sum==buildv+n)
    {
        ans=min(ans,usem);
        return 1;
    }
    for(auto v:G[x])
    {
        //cout<<x<<"@"<<v.v<<endl;
        if(dis[x]+v.w<dis[v.v])
        {
            if(v.v<=n)
            {
                if(dis[v.v]!=0x3f3f3f3f)
                {
                    usem-=dis[v.v];
                    usem+=v.w+dis[x];
                }
                else
                {
                    usem+=v.w;
                }
                dis[v.v]=dis[x]+v.w;
                //cout<<x<<" "<<v.v<<endl;
                sum++;
                if(dfs(v.v,x))
                {
                    return 1;
                }
            }
            else if(v.v>n&&a[v.v-n])
            {
                if(dis[v.v]==0x3f3f3f3f)
                {
                    usem+=c[v.v]+v.w;
                }
                else
                {
                    usem-=dis[v.v];
                    usem+=dis[x]+v.w;
                }
                dis[v.v]=dis[x]+v.w;
                sum++;
                if(dfs(v.v,x))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void solve(int x,int num)
{
    if(x>k)
    {
        memset(dis,0x3f,sizeof(dis));
        sum=1;
        dis[1]=0;
        buildv=num;
        usem=0;
        dfs(1,1);
        return ;
    }
    a[x]=1;
    solve(x+1,num+1);
    a[x]=0;
    solve(x+1,num);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=n+1; i<=n+k; i++)
    {
        int hh;
        cin>>hh;
        c[i]=hh;
        for(int j=1; j<=n; j++)
        {
            int h;
            cin>>h;
            G[i].push_back({j,h});
            G[j].push_back({i,h});
        }
    }
    for(int i=1; i<=n+k; i++)
    {
        sort(G[i].begin(),G[i].end(),cmp);
    }
    solve(1,0);
    cout<<ans<<endl;
}
