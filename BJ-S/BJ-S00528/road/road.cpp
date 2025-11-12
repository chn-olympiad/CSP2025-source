#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e6+5,K=15;
struct node{int u,v,w;}e[M];
int n,m,k,c[K],f[N],sz[N];vector<node> dp[1<<K],ek[K];ll minn;
inline int root(int x){return (f[x]==x?x:f[x]=root(f[x]));}
inline void merge(int x,int y)
{
    if(sz[x]>sz[y]) f[y]=x,sz[y]=0;
    else f[x]=y,sz[x]=0;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1,x;j<=n;j++) cin>>x,ek[i].push_back({i+n,j,x});
        sort(ek[i].begin(),ek[i].end(),[](node x,node y){return x.w<y.w;});
    }
    sort(e+1,e+m+1,[](node x,node y){return x.w<y.w;});
    for(int i=1;i<=n+k;i++) f[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int ru=root(e[i].u),rv=root(e[i].v);
        if(ru!=rv) dp[0].push_back(e[i]),merge(ru,rv),minn+=e[i].w;
    }
    for(int i=1;i<(1<<k);i++)
    {
        for(int j=1;j<=n+k;j++) f[j]=j,sz[j]=1;
        ll ans=0;for(int j=0;j<k;j++) if((i>>j)&1) ans+=c[j+1];
        int j=i&-i,l=log2(j)+1,i1=0,i2=0;
        while(i1<int(dp[i-j].size())&&i2<int(ek[l].size()))
        {
            int u,v,w=min(dp[i-j][i1].w,ek[l][i2].w);
            if(dp[i-j][i1].w<ek[l][i2].w) u=dp[i-j][i1].u,v=dp[i-j][i1].v,i1++;
            else u=ek[l][i2].u,v=ek[l][i2].v,i2++;
            int ru=root(u),rv=root(v);
            if(ru!=rv) dp[i].push_back({u,v,w}),merge(ru,rv),ans+=w;
        }
        while(i1<int(dp[i-j].size()))
        {
            int u=dp[i-j][i1].u,v=dp[i-j][i1].v,w=dp[i-j][i1].w;
            int ru=root(u),rv=root(v);
            if(ru!=rv) dp[i].push_back({u,v,w}),merge(ru,rv),ans+=w;
            i1++;
        }
        while(i2<int(ek[l].size()))
        {
            int u=ek[l][i2].u,v=ek[l][i2].v,w=ek[l][i2].w;
            int ru=root(u),rv=root(v);
            if(ru!=rv) dp[i].push_back({u,v,w}),merge(ru,rv),ans+=w;
            i2++;
        }
        minn=min(minn,ans);
    }
    cout<<minn;
    return 0;
}