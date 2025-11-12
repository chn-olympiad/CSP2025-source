#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int u,v,w;
};
int fa[10005];
vector<node>edge;
int f(int x)
{
    return (fa[x]==x?x:fa[x]=f(fa[x]));
}
void unite(int x,int y)
{
    fa[f(x)]=f(y);
}
int kruskal()
{
    long long sum=0,cnt=0;
    for(auto [a,b,c]:edge)
    {
        if(f(a)!=f(b))
        {
            sum+=c;
            unite(a,b);cnt++;
        }
        if(cnt==n-1)    break;
    }
    return sum;
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    if(k==0)
    {
        sort(edge.begin(),edge.end(),cmp);
        cout<<kruskal();
    }
    else
    {
        int b[k+1][n+1],c[n+1][n+1];
        for(int i=1;i<=k;i++)
        {
            int c;cin>>c;
            for(int j=1;j<=n;j++)
            {
                cin>>b[i][j];
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                c[i][j]=1e10;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int y=1;y<=k;y++)
                {
                    c[i][j]=min(b[y][i]+b[y][j],c[i][j]);
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                edge.push_back({i,j,c[i][j]});
            }
        sort(edge.begin(),edge.end(),cmp);
        cout<<kruskal();
    }
}
