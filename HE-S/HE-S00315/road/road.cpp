#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20,M=3e6+10;
int p[N];
int cnt;
struct node
{
    int u,v;
    ll w;
} edge[M];
ll vl[15];
ll ans=LONG_LONG_MAX;
int n,m,k;
bool can[15];

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(p[x]==x) return x;
    p[x]=find(p[x]);
    return p[x];
}
ll kurskal()
{
    ll res=0;
    for(int i=1;i<=n+k;i++) p[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        ll w=edge[i].w;
        if(u>n)
        {
            if(!can[u-n]) continue;
        }

        int root1=find(u),root2=find(v);
        if(root1!=root2)
        {
            p[root1]=root2;
            res+=w;
        }
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        edge[++cnt]={u,v,w};
    }

    for(int i=1;i<=k;i++)
    {
        cin>>vl[i];
        for(int j=1;j<=n;j++)
        {
            ll w;
            cin>>w;
            edge[++cnt]={i+n,j,w};
        }
    }

    sort(edge+1,edge+cnt+1,cmp);
    for(int i=0;i<=(1<<k)-1;i++)
    {
        ll res=0;
        memset(can,0,sizeof(can));
        for(int j=0;(1<<j)<=i;j++)
        {
            if((1<<j) & i) can[j+1]=1,res+=vl[j+1];
        }
        res+=kurskal();
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
