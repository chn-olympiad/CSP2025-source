#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge {
    int i,j,k;
} g[10000005];
bool cmp(edge a,edge b) {
    return a.k<b.k;
}
int fa[5000005],w[5000005];
bool vis[5000005];
int n,m,k;
void init(int m) {
    for(int i=1;i<=m;i++)
        fa[i]=i;
}
int find(int x) {
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void merge(int a,int b) {
    fa[find(b)]=a;
}
int krus(int ms) {
    int res=0;
    init(ms);
    sort(g+1,g+ms+1,cmp);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=ms;i++) {
        if(g[i].i>g[i].j)
            swap(g[i].i,g[i].j);
        if(g[i].j>n&&!vis[g[i].j]) {
            vis[g[i].j]=1;
            res+=w[g[i].j];
        }
        if(find(g[i].i)!=find(g[i].j)) {
            res+=g[i].k;
            merge(g[i].i,g[i].j);
        }
    }
    return res;
}
int ans=0;
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    int t1=clock();
    for(int i=1;i<=m;i++) {
        int u,v,k;
        scanf("%lld %lld %lld",&u,&v,&k);
        g[i]={u,v,k};
    }
    ans=krus(m);
    int s=1;
    for(int i=1;i<=k;i++) {
        scanf("%lld",w+s+n);
        for(int p=1;p<=n;p++) {
            int k;
            scanf("%lld",&k);
            g[m+p]={n+s,p,k};
        }
        int nw=krus(m+n*s);
        if(nw<=ans) {
            ans=nw;
            s++;
        }
    }
    printf("%lld",ans);
    return 0;
}