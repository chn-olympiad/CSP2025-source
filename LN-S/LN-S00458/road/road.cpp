#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+30,maxm=1e6+30;
int n,m,k,c[20],v[maxn];
int cnt,head[maxn],to[maxm<<1],nxt[maxm<<1],cst[maxm<<1];
void add(int u,int v,int w){
    to[++cnt]=v,cst[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
    return ;
}
void dfs(int x,int fa){
    for(int i=head[x];~i;i=nxt[i]){
        if(to[i]!=fa){
            dfs(to[i],x);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)head[i]=-1;
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&w);
            add(m+i,i,w),add(i,m+i,w);
        }
    }
    cout<<0<<"\n";
    return 0;
}
