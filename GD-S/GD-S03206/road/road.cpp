#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20,M=1e6+5;
const ll inf=1e18;
int n,m,k,u,v,w,nn,c[15],fa[N],id[15],sz[15];
ll Res,ans;
struct E{int u,v,w;}e[M],a[15][N];
inline bool cmp(E p,E q){return p.w<q.w;}
inline int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
inline void kruskal(ll&res){
    iota(fa+1,fa+n+k+1,1),fill(id,id+k+1,1);
    for(int t=1;t<nn;t++){
        int nid=-1;
        for(int i=1;i<=k;i++){
            while(id[i]<=sz[i]&&find(a[i][id[i]].u)==find(a[i][id[i]].v)) ++id[i];
            if(id[i]<=sz[i]&&(nid<0||a[i][id[i]].w<a[nid][id[nid]].w)) nid=i;
        }
        while(id[0]<=m&&find(e[id[0]].u)==find(e[id[0]].v)) ++id[0];
        if(id[0]<=m&&(nid<0||e[id[0]].w<a[nid][id[nid]].w))
            fa[find(e[id[0]].u)]=find(e[id[0]].v),res+=1ll*e[id[0]].w;
        else if(nid>0)
            fa[find(a[nid][id[nid]].u)]=find(a[nid][id[nid]].v),res+=1ll*a[nid][id[nid]].w;
    }
}
int main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k,ans=inf;
    for(int i=1;i<=m;i++) cin>>u>>v>>w,e[i]={u,v,w};
    sort(e+1,e+m+1,cmp);
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++) cin>>w,a[j][i]={i,j+n,w};
        sort(a[j]+1,a[j]+n+1,cmp);
    }
    for(int s=0;s<1<<k;s++){
        Res=0,nn=n,fill(sz+1,sz+k+1,0);
        for(int j=1;j<=k;j++) if(s>>j-1&1) ++nn,Res+=1ll*c[j],sz[j]=n;
        kruskal(Res),ans=min(ans,Res);
    }
    cout<<ans;
    return 0;
}