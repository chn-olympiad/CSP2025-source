#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
typedef long long ll;
int n,m,k,cnt,tot,fa[M],a[15][N],ct[15],c[15],d[M],vis[15];
ll ans=0;
inline int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}
struct edge{
    int u,v,w;
    bool operator < (const edge &b)const{
        return w < b.w;
    }
}e[M],g[M<<1]; 
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        ans+=e[i].w;cnt++;
        fa[v]=u;
        g[cnt]=e[i];
        if(cnt==n-1) break;
    }
    // for(int i=1;i<=m;i++) g[i]=e[i];
    // cout<<ans<<'\n';
    for(int i=1;i<(1<<k);i++){
        tot=n-1;cnt=0;
        ll res=0;int ctt=0;
        memset(vis,0,sizeof vis);
        for(int j=1;j<=k;j++){
            if(!(i & (1<<(j-1)))) continue;
            // cout<<j<<' ';
            for(int p=1;p<=n;p++)
            g[++tot]={j+n,p,a[j][p]};
            res+=c[j];
            vis[j]=1;ctt++;
        }
        // cout<<'\n';
        // cout<<tot<<'\n';
        sort(g+1,g+tot+1);
        for(int j=1;j<=n+k;j++) d[j]=0;
        for(int j=1;j<=n+k;j++) fa[j]=j;
        // cout<<i<<'\n';
        for(int j=1;j<=tot;j++){
            int u=find(g[j].u),v=find(g[j].v);
            if(u==v) continue;
            // cout<<g[j].u<<' '<<g[j].v<<' '<<g[j].w<<'\n';
            res+=g[j].w;cnt++;
            fa[v]=u;
            d[g[j].u]++,d[g[j].v]++;
            if(cnt==n+ctt-1) break;
        }
        // if(res==504898585) cout<<i<<'\n';
        if(cnt != n+ctt-1) continue;
        // cout<<res<<'\n';
        int flag=0;
        for(int j=1;j<=k;j++)
        if(vis[j] && d[j+n] < 2) flag=1;
        if(flag) continue;
        ans=min(ans,res);
        // cout<<res<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}