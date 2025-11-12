#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
int c[13];
int a[13][10010];
long long ans=0;
struct Edge
{
    int u,v,w;
};
vector <Edge> e;
int fa[10010];
int find(int i)
{
    return fa[i]==i?i:find(fa[i]);
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=k;i++)
        if(c[i]==0)
            for(int j=1;j<=n;j++)
                for(int l=j+1;l<=n;l++)
                        e.push_back({j,l,a[i][j]+a[i][l]});
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e.begin(),e.end(),cmp);

    for(auto e_:e)
    {
        int u_=e_.u,v_=e_.v,w_=e_.w;
        if(find(u_)!=find(v_))
        {
            fa[find(v_)]=find(u_);
            ans+=w_;
        }
    }
    cout<<ans;
    return 0;
}
