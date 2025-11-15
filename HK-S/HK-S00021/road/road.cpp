#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<20;
const int M=1<<15;
struct node{
    int u,v,w;
    bool operator<(const node& cmp)const{return w<cmp.w;}
};
int n,m,k,tot;
ll ans;
int l[15];
ll sum[15];
node tmp[15][N];
node t[N],o[N];
int cost[15];
node a[15][M];
int fa[N];
int find(int u){
    if(fa[u]!=u) fa[u]=find(fa[u]);
    return fa[u];
}
void merge(node *a,int l1,node *b,int l2,node *tmp,int &l){
    static node p[N]={};
    int tot=0,it1=1,it2=1;
    while(it1<=l1&&it2<=l2) if(a[it1]<b[it2]) p[++tot]=a[it1++];
    else p[++tot]=b[it2++];
    while(it1<=l1) p[++tot]=a[it1++];
    while(it2<=l2) p[++tot]=b[it2++];
    l=l1+l2;
    for(int i=1;i<=l;i++) tmp[i]=p[i];
}
ll prim(node *a,int l){
    ll ret=0;
    for(int i=1;i<=n+10;i++) fa[i]=i;
    for(int i=1;i<=l;i++){
        int fx=find(a[i].u),fy=find(a[i].v);
        if(fx!=fy) fa[fx]=fy,ret+=a[i].w;
    }
    return ret;
}
void dfs(int pos=1){
    if(pos==k+1){
        ans=min(ans,prim(tmp[pos-1],l[pos-1])+sum[pos-1]);
        return;
    }
    l[pos]=l[pos-1],sum[pos]=sum[pos-1];
    for(int i=1;i<=l[pos];i++) tmp[pos][i]=tmp[pos-1][i];
    dfs(pos+1);
    sum[pos]+=cost[pos];
    merge(tmp[pos],l[pos],a[pos],n,tmp[pos],l[pos]);
    dfs(pos+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w),t[i]={u,v,w};
    }
    sort(t+1,t+m+1);
    for(int i=1;i<=n+10;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int fx=find(t[i].u),fy=find(t[i].v);
        if(fx!=fy) fa[fx]=fy,ans+=t[i].w,tmp[0][++l[0]]=t[i];
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&cost[i]);
        for(int j=1;j<=n;j++){
            int u=i+n,v=j,w;
            scanf("%d",&w);
            a[i][j]={u,v,w};
        }
        sort(a[i]+1,a[i]+n+1);
    }
    dfs();
    printf("%lld\n",ans);
    return 0;
}
