#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,fa[10020],siz[10020],cnt,lg[1025],f[1025];
struct node{
    int u,v;long long w;
}edge[1000020],g[11][10020],dp[1025][10020];
int len[1025];
bool cmp(node a,node b){return a.w<b.w;}
void init(){for(int i = 1;i<=n+k;i++)siz[fa[i]=i]=1;}
int find(int x){return(x==fa[x]?x:fa[x]=find(fa[x]));}
long long ans = 1e18,c[11],res,sum[1025];
void merge(int id,int x,int y,long long w){
    int fx = find(x),fy = find(y);
    if(fx==fy) return;
    if(siz[fx]<siz[fy]) swap(fx,fy);
    fa[fy] = fx;
    siz[fx] += siz[fy];
    cnt--,res += w;
    dp[id][++len[id]] = (node){x,y,w};
}int lowbit(int x){return x&-x;}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=m;i++) scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);sort(edge+1,edge+m+1,cmp);
    lg[0] = -1;
    for(int i = 1;i<=(1<<k);i++) lg[i] = lg[i>>1]+1,f[i] = f[i&(i-1)]+1;
    for(int i = 1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j = 1;j<=n;j++){
            long long a;scanf("%lld",&a);
            g[i][j] = (node){n+i,j,a};
        }sort(g[i]+1,g[i]+n+1,cmp);
        g[i][n+1] = (node){0,0,(long long)1e18};
    }cnt = n,res = 0;init();
    for(int i = 1;i<=m&&cnt>1;i++) merge(0,edge[i].u,edge[i].v,edge[i].w);
    dp[0][++len[0]] = (node){0,0,(long long)1e18};
    ans = min(ans,res);
    for(int s = 1;s<(1<<k);s++){
        int p1 = s&(s-1),p2 = lg[lowbit(s)]+1;
        res = sum[s] = sum[p1]+c[p2];
        cnt = n+f[s];init();
        for(int i = 1,j = 1;(i<=len[p1]||j<=n)&&cnt>1;){
            if(dp[p1][i].w<g[p2][j].w) merge(s,dp[p1][i].u,dp[p1][i].v,dp[p1][i].w),i++;
            else merge(s,g[p2][j].u,g[p2][j].v,g[p2][j].w),j++;
        }dp[s][++len[s]] = (node){0,0,(long long)1e18};
        ans = min(ans,res);
    }printf("%lld",ans);
    return 0;
}
