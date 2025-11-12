#include<bits/stdc++.h>
using namespace std;

//main

#define ll long long
const int N=1e3+7,M=1e6+7,K=14;

//kruskal+edge

int n,m,k;
struct E{
    int u,v;ll w;
}e[M+M];
vector<pair<int,int>>g[N];
ll a[K][N],c[K];
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}bool cmp(E x,E y){return x.w<y.w;}

//beizeng

int dep[N],f[N][20],mx[N][20];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(auto it:g[x]){
        int v=it.first,w=it.second;
        if(v==fa)continue;
        mx[v][0]=w;
        dfs(v,x);
    }
}
void init(){
    for(int j=1;j<=15;j++){
        for(int i=1;i<=n;i++){
            f[i][j]=f[f[i][j-1]][j-1];
            mx[i][j]=max(mx[i][j-1],mx[f[i][j-1]][j-1]);
        }
    }
}int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int ans=mx[u][0];
    for(int i=15;i>=0;i--){
        if(dep[f[u][i]]>=dep[v]){
            ans=max(ans,mx[u][i]);
            u=f[u][i];
        }
    }if(u==v)return ans;
    for(int i=15;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            ans=max({ans,mx[u][i],mx[v][i]});
            u=f[u][i];v=f[v][i];
        }
    }return max({ans,mx[u][0],mx[v][0]});
}

//main
void solve(){
    int iss[K]={0};
    int idx=m;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0)iss[i]=j;
        }for(int j=1;j<=n;j++){
            if(j!=iss[i])e[++idx].u=iss[i],e[idx].v=j,e[idx].w=a[i][j];
        }
    }
    sort(e+1,e+idx+1,cmp);
    int times=0;ll krus=0;int tot=n;
    for(int i=1;i<=idx;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        u=find(u);v=find(v);
        if(u!=v){
            fa[u]=v;
            times++;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            krus+=w;
        }if(times==tot-1)break;
    }cout<<krus;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    }bool chave0=1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0)chave0=0;
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }if(chave0){solve();return 0;}
    sort(e+1,e+m+1,cmp);
    int times=0;ll krus=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        u=find(u);v=find(v);
        if(u!=v){
            fa[u]=v;
            times++;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            krus+=w;
        }if(times==n-1)break;
    }dfs(1,0);
    for(int i=1;i<=k;i++){
        ll ms=0;
        for(int u=1;u<n;u++){
            for(int v=u+1;v<=n;v++){
                ll lc=lca(u,v);
                ll jc=a[i][u]+a[i][v];
                if(jc<lc)ms+=lc-jc,a[i][u]=a[i][v]=1e10+7;
            }
        }krus=min(krus,krus+c[i]-ms);
    }cout<<krus;
    return 0;
}
