#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int u;
    int v;
    int w;
}eg[2000005],eg_[100005];
int a[15][10005];
bool lg[2000005];
int fa[20005];
bool vis[15];
int c[15];
int n,m,k;
int cnt,tot;
long long ans;
bool cmp(node x,node y){return x.w < y.w;}
int fd(int x){
    if(fa[x] == x)return x;
    fa[x] = fd(fa[x]); return fa[x];
}
void nt(){
    for(int i = 1;i <= tot;i++)eg[i] = eg_[i];
    for(int j = 1;j <= k;j++){
        if(!vis[j])continue; cnt++;
        for(int i = 1;i <= n;i++)
            {tot++; eg[tot].u = i; eg[tot].v = cnt; eg[tot].w = a[j][i];}
    }
    return;
}
long long sv(){
    sort(eg+1,eg+tot+1,cmp); long long sum = 0;
    for(int i = 1;i <= cnt;i++)fa[i] = i;
    for(int i = 1;i <= tot;i++){
        if(fd(eg[i].u) == fd(eg[i].v))continue;
        fa[fa[eg[i].u]] = fa[eg[i].v]; sum+= eg[i].w; lg[i] = 1;
    }
    cnt = n; tot = n-1; return sum;
}
void dfs(int stp,long long sum){
    if(stp == k+1){nt(); ans = min(ans,sv()+sum); return;}
    dfs(stp+1,sum); vis[stp] = 1; dfs(stp+1,sum+c[stp]); vis[stp] = 0; return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k); cnt = n; tot = m;
    for(int i = 1;i <= m;i++)
        scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].w);
    for(int j = 1;j <= k;j++){
        scanf("%d",&c[j]);
        for(int i = 1;i <= n;i++)scanf("%d",&a[j][i]);
    }
    ans = sv(); tot = 0;
    for(int i = 1;i <= m;i++)if(lg[i]){tot++; eg_[tot] = eg[i];}
    dfs(1,0); printf("%lld\n",ans);
    return 0;
}