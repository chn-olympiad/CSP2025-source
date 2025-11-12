#include <bits/stdc++.h>
using namespace std;
const int N=10020;
const int M=1100000;
struct node
{
    short u,v;
    int w;
};
bool uv[N][N];
bool cmp(node x,node y)
{
    if(uv[x.u][x.v]!=uv[y.u][y.v])
    {
        return uv[x.u][x.v]>uv[y.u][y.v];
    }
    return x.w<y.w;
}
int n,m,k,all;
node a[M];
short f[N];
int c[15];
bool vis[15];
long long ans=1e18;
int findr(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    f[x]=findr(f[x]);
    return f[x];
}
void solve()
{
    long long sum=0;
    int fun=n;
    for(int i=1;i<=k;i++)
    {
        if(vis[i]==1)
        {
            for(int j=1;j<=n;j++)
            {
                uv[n+i][j]=1;
            }
            sum=sum+c[i];
            fun++;
        }
    }
    for(int i=1;i<=n+k;i++)
    {
        f[i]=i;
    }
    sort(a+1,a+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int ru=findr(a[i].u);
        int rv=findr(a[i].v);
        if(ru!=rv)
        {
            //cout<<fua[i].u<<" "<<fua[i].v<<endl;
            f[ru]=rv;
            cnt++;
            sum=sum+a[i].w;
        }
        if(cnt==fun-1)
        {
            break;
        }
    }
    //cout<<sum<<endl<<endl;
    ans=min(ans,sum);
    for(int i=1;i<=k;i++)
    {
        if(vis[i]==1)
        {
            for(int j=1;j<=n;j++)
            {
                uv[n+i][j]=0;
            }
        }
    }
}
void dfs(int x)
{
    if(x>k)
    {
        solve();
        return ;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
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
        cin>>a[i].u>>a[i].v>>a[i].w;
        uv[a[i].u][a[i].v]=1;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            a[++m]=node{n+i,j,w};
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
