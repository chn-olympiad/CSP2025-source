#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+100,M=1e6+100;
int n,m,k;
struct edge{
    int x,y;ll w;
    void read(){
        scanf("%d%d%lld",&x,&y,&w);
    }
}e[M],en[N];
ll c[N],g[11][N];
bool cmp(edge a,edge b){
return a.w<b.w;}
bool vis[N];ll ans=0;
bool isp[11];
int fa[N];
int find(int x){
    if (fa[x]==0)return 0;
    while (fa[x]!=fa[fa[x]])fa[x]=fa[fa[x]];
    return fa[x];
}
void dfs(int pos){
    if (pos>k){
            ll sum=0;
    memset(fa,0,sizeof fa);
    int tot=0;
    for (int i=1;i<n;i++)e[++tot]=en[i];
    for (int i=1;i<=k;i++){
        if (isp[i]){
            sum+=c[i];
            for (int j=1;j<=n;j++)e[++tot]={j,i+n,g[i][j]};
        }
    }
    if (tot==n-1)return ;
    sort(e+1,e+tot+1,cmp);
    for (int i=1;i<=tot;i++){
        int ax=find(e[i].x),ay=find(e[i].y);
        if (ax==ay&&ax!=0)continue;
        if (ax==0&&ay==0)fa[e[i].x]=fa[e[i].y]=e[i].x;
        else if (ax==0)fa[e[i].x]=ay;
        else if (ay==0)fa[e[i].y]=ax;
        else {
            fa[ax]=fa[ay];
        }
        sum+=e[i].w;
        if (sum>=ans)return ;
    }
    ans=min(ans,sum);
            return ;
    }
    dfs(pos+1);
    isp[pos]=1;
    dfs(pos+1);
    isp[pos]=0;
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++){
        e[i].read();
    }
    for (int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for (int j=1;j<=n;j++)scanf("%lld",&g[i][j]);
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0;
    for (int i=1;i<=m;i++){
        int ax=find(e[i].x),ay=find(e[i].y);
        if (ax==ay&&ax!=0)continue;
        if (ax==0&&ay==0)fa[e[i].x]=fa[e[i].y]=e[i].x;
        else if (ax==0)fa[e[i].x]=ay;
        else if (ay==0)fa[e[i].y]=ax;
        else {
            fa[ax]=fa[ay];
        }
        ans+=e[i].w;
        en[++cnt]=e[i];
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
