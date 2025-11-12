#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,w,flag;
}edge[1000010],tmp_edge[1000010],mst_edge[10010],cycle[10][10010];
struct Node{
    int id,val;
}tmp[10010];
bool operator <(const Node &lhs,const Node &rhs){
    return lhs.val<rhs.val;
}
int edge_tot;
bool operator <(const Edge &lhs,const Edge &rhs){
    return lhs.w<rhs.w;
}
int n,m,k,p[10010],c[10],a[10][10010];
int Find(int pos){
    if(p[pos]!=pos) p[pos]=Find(p[pos]);
    return p[pos];
}
long long MST(){
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    long long sum=0;
    int cnt_edge=0;
    for(int i=1;i<=edge_tot;i++){
        int u=Find(edge[i].u),v=Find(edge[i].v),w=edge[i].w;
        if(u!=v){
            p[u]=v;
            sum+=w;
            mst_edge[++cnt_edge]=edge[i];
            if(cnt_edge==n-1){
                return sum;
            }
        }
    }
}
long long ans;
void dfs(int cur,long long cost){
    if(cur==k){
        ans=min(ans,cost+MST());
        return ;
    }
    int pre1=1,pre2=1,tot=0;
    while(pre1<=edge_tot  &&  pre2<n){
        if(edge[pre1]<cycle[cur][pre2]){
            tmp_edge[++tot]=edge[pre1++];
        }
        else{
            tmp_edge[++tot]=cycle[cur][pre2++];
        }
    }
    while(pre1<=edge_tot){
        tmp_edge[++tot]=edge[pre1++];
    }
    while(pre2<n){
        tmp_edge[++tot]=cycle[cur][pre2++];
    }
    edge_tot=tot;
    for(int i=1;i<=edge_tot;i++){
        edge[i]=tmp_edge[i];
    }
    dfs(cur+1,cost+c[cur]);
    tot=0;
    for(int i=1;i<=edge_tot;i++){
        if(edge[i].flag!=cur){
            tmp_edge[++tot]=edge[i];
        }
    }
    edge_tot=tot;
    for(int i=1;i<=edge_tot;i++){
        edge[i]=tmp_edge[i];
    }
    dfs(cur+1,cost);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        edge_tot++;
        scanf("%d %d %d",&edge[edge_tot].u,&edge[edge_tot].v,&edge[edge_tot].w);
        edge[edge_tot].flag=-1;
    }
    sort(edge+1,edge+1+edge_tot);
    for(int i=0;i<k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            tmp[j]=(Node){j,a[i][j]};
        }
        sort(tmp+1,tmp+1+n);
        c[i]+=tmp[1].val;
        for(int j=2;j<=n;j++){
            cycle[i][j-1]=(Edge){tmp[1].id,tmp[j].id,tmp[j].val,i};
        }
    }
    ans=MST();
    edge_tot=n-1;
    for(int i=1;i<=edge_tot;i++){
        edge[i]=mst_edge[i];
    }
    dfs(0,0);
    printf("%lld",ans);
    return 0;
}
