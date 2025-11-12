#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int n,m,k,idx;
const int M=2e6+10,N=2e4+10;
struct node
{
    int u,v,w,id;
    friend bool operator <(const node &a,const node &b)
    {
        return a.w<b.w;
    }
}q[M];
int g[N],sz[N],c[N],a[11][N];
int find(int x)
{
    return x==g[x]?x:g[x]=find(g[x]);
}
inline void op(int x,int y)
{
    x=find(x),y=find(y);
    if(sz[x]>sz[y]) swap(x,y);
    g[x]=y;sz[y]+=sz[x];
}
void cl()
{
    for(int i=1;i<=n+k;i++) g[i]=i,sz[i]=1;
}
ll calc(int S)
{
    cl();
    ll ans=0;
    int cnt=0,pcnt=__builtin_popcount(S);
    for(int i=0;i<k;i++) if(S>>i&1) ans+=c[i];
    for(int i=1;i<=idx;i++)
    {
        if(q[i].id!=k&&(!(S>>q[i].id&1))) continue;
        if(find(q[i].u)==find(q[i].v)) continue;
        op(q[i].u,q[i].v),cnt++;
        ans+=q[i].w;
        if(cnt==pcnt+n-1) break;
    }
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>q[i].u>>q[i].v>>q[i].w,q[i].id=k;
    cl();
    sort(q+1,q+m+1);
    for(int i=1;i<=m;i++)
    {
        int u=q[i].u,v=q[i].v,w=q[i].w;
        if(find(u)==find(v)) continue;
        q[++idx]={u,v,w,k};
        op(u,v);
    }
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) 
        {
            cin>>a[i][j];
            q[++idx]={i+n+1,j,a[i][j],i};
        }
    }
    sort(q+1,q+idx+1);
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++) ans=min(ans,calc(i));
    cout<<ans;
    return 0;
}