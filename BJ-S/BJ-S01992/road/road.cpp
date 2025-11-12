#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define int long long
#define N 10050
#define M 9000009
using namespace std;
int n, m, k;
struct edge
{
    int u,v,w;
    bool operator < (const edge &ed) const
    {
        return w<ed.w;
    }
};
namespace k0
{
    int fa[N];
    edge e[M];
    int findfa(int x)
    {
        if(fa[x]==x) return x;
        return findfa(fa[x]);
    }
    void mian()
    {
        for(int i=1; i<=m; i++)
        {
            edge eg;
            cin>>eg.u>>eg.v>>eg.w;
            e[i]=eg;
        }
        sort(e+1, e+1+m);
        for(int i=1; i<=n; i++) fa[i]=i;
        int cnt=0;
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            edge eg=e[i];
            int startpoint=eg.u;
            int endpoint=eg.v;
            int cost=eg.w;
            if(findfa(endpoint)!=startpoint)
            {
                fa[endpoint]=startpoint;
                cnt++;
                ans+=cost;
            }
            if(cnt==n-1) break;
        }
        cout << ans << endl;
        return ;
    }
}
namespace A
{
    int fa[N];
    edge e[M];
    int a[N][N];
    int ids[M];
    bool vis[N][N];
    bool b[N];
    int findfa(int x)
    {
        if(fa[x]==x) return x;
        if(b[x]) return fa[x];
        b[x]=1;
        return fa[x]=findfa(fa[x]);
    }
    void mian()
    {
        for(int i=1; i<=m; i++)
        {
            edge eg;
            cin>>eg.u>>eg.v>>eg.w;
            e[i]=eg;
        }
        sort(e+1, e+1+m);
        for(int i=1; i<=n; i++) fa[i]=i;
        int cnt=0;
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            edge eg=e[i];
            int startpoint=eg.u;
            int endpoint=eg.v;
            int cost=eg.w;
            if(findfa(endpoint)!=startpoint)
            {
                fa[endpoint]=startpoint;
                cnt++;
                ans+=cost;
                ids[cnt]=i;
            }
            if(cnt==n-1) break;
        }
        cout << ans << '\n';
        for(int i=1; i<=k; i++)
        {
            int c;
            cin >> c;
            for(int j=1; j<=n; j++)
            {
                int t;
                cin>>t;
                a[i][j]=t;
                a[j][i]=t;
            }
        }

        for(int i=cnt; i>=1; i--)
        {
            for(int j=1; j<=k; j++)
            {
                int q=0;
                if((!vis[e[ids[i]].u][j]))
                    q+=a[e[ids[i]].u][j];
                if(!vis[j][e[ids[i]].v])
                    q+=a[j][e[ids[i]].v];
                if(e[ids[i]].w>q)
                {

                    vis[e[ids[i]].u][j]=vis[j][e[ids[i]].u]=1;
                    vis[j][e[ids[i]].v]=vis[e[ids[i]].v][j]=1;
                    ans-=e[ids[i]].w;
                    ans+=q;
                }
            }
        }
        cout << ans << '\n';
        return ;
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        k0::mian();
        return 0;
    }else{
        A::mian();
        return 0;
    }
    return 0;
}
