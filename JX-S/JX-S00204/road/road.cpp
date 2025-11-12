#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,M=1e6+10,K=12;
const ll INF=1e18;
ll w[2*N];
int h[N],e[2*N],ne[2*N],idx;
void add(int a,int b,ll c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
struct E{
    ll u,v,w;
    bool operator <(const E& W) const{
        return w<W.w;
    }
}eg[M];
int n,m,k,ff[N];
int find(int x){
    if(ff[x]!=x) ff[x]=find(ff[x]);
    return ff[x];
}
ll f[N][K],g[N][K],a[N][K],tot[N],ans,tmp,res;
bool st[K];
// f[i][j]: cj contain i
// g[i][j]: cj except i contain fa
void dfs1(int u,int fa){
    for(int i=h[u]; i!=-1; i=ne[i]){
        int v=e[i];
        if(v^fa) dfs1(v,u);
    }
    for(int t=1; t<=k; t++){
        if(!st[t]) continue;
        f[u][t]=a[u][t];
        for(int i=h[u]; i!=-1; i=ne[i]){
            int v=e[i];
            if(v^fa) f[u][t]=min(f[u][t],f[v][t]);
        }
    }
}
void dfs2(int u,int fa){
    for(int t=1; t<=k; t++){
        if(!st[t]) continue;
        ll mi=INF,mmi=INF,p=0;
        for(int i=h[u]; i!=-1; i=ne[i]){
            int v=e[i];
            if(v^fa){
                if(mi>=f[v][t]) mmi=mi, mi=f[v][t], p=v;
                else if(mmi>f[v][t]) mmi=f[v][t];
            }
        }
        for(int i=h[u]; i!=-1; i=ne[i]){
            int v=e[i];
            if(v^fa){
                ll ex=p==v?mmi:mi;
                g[v][t]=min({g[u][t], a[u][t], ex});
                //if(v==3) printf("%lld %lld\n",g[v][t], f[v][t]);
                tot[v]=min(tot[v], g[v][t]+f[v][t]);
            }
        }
    }
    for(int i=h[u]; i!=-1; i=ne[i]){
        int v=e[i];
        if(v^fa){
            if(tot[v]<w[i]){
                res-=w[i]-tot[v];
            }
            dfs2(v,u);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(h,-1,sizeof h);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) ff[i]=i;
    for(int i=1; i<=m; i++){
        int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
        eg[i]={a,b,c};
    }
    bool flag=1;
    for(int i=1; i<=k; i++){
        scanf("%lld",&a[0][i]); if(a[0][i]) flag=0;
        for(int j=1; j<=n; j++){
            scanf("%lld",&a[j][i]);
            if(a[j][i]) flag=0;
        }
    }
    if(flag&&k){
        cout<<0;
        return 0;
    }
    sort(eg+1,eg+m+1);
    for(int i=1; i<=m; i++){
        ll u=eg[i].u, v=eg[i].v, w=eg[i].w;
        if(find(u)!=find(v)){
            ff[find(u)]=find(v);
            tmp+=w;
            add(u,v,w), add(v,u,w);
        }
    }
    //----------------
    if(!k){
        printf("%lld",tmp);
        return 0;
    }
    ans=tmp;
    for(int s=1; s<=(1<<k); s++){
        memset(st,0,sizeof st);
        memset(f,0x3f,sizeof f);
        memset(g,0x3f,sizeof g);
        memset(tot,0x3f,sizeof tot);
        res=tmp;
        for(int i=0; i<k; i++)
            if(s>>i&1) st[i+1]=1, res+=a[0][i+1];
        dfs1(1,0);
        dfs2(1,0);
        ans=min(ans, res);
    }
    printf("%lld",ans);
    return 0;
}
