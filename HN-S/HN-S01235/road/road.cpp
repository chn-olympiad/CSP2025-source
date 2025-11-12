#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+15,M=1e6+5;
const ll INF=1e18;
int n,m,k;
ll ans=INF;
struct edge{
    int u,v,w;
}e[M],a[N];
struct pl{
    int c;
    struct node{
        int x,w;
    }to[N];
    void init(){
        sort(to+1,to+n+1,[](node x,node y){return x.w<y.w;});
    }
}w[12];
int pre[N],sz[N];
inline int find(int p){
    if(pre[p]==p) return p;
    return pre[p]=find(pre[p]);
}
inline bool merge(int x,int y){
    assert(x&&y);

    x=find(x),y=find(y);
    if(x==y) return 0;
    if(sz[x]>sz[y]) swap(x,y);
    pre[x]=y;
    sz[y]+=sz[x];
    return 1;
}
int b[20],tot;
int now[20];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=1;i<=m;i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++) {
        cin>>w[i].c;
        for(int j=1;j<=n;j++) {
            cin>>w[i].to[j].w;
            w[i].to[j].x=j;
        }
        w[i].init();
    }
    sort(e+1,e+m+1,[](edge x,edge y){return x.w<y.w;});
    int cnt=0;ll res=0;
    for(int i=1;i<=m;i++) {
        int u=e[i].u,v=e[i].v;
        u=find(u),v=find(v);
        if(u!=v) {
            a[++cnt]=e[i];
            pre[u]=v;
            res+=e[i].w;
        }
    }
    // return 0;
    ans=min(ans,res);
    for(int S=1;S<(1<<k);S++) {
        res=0;
        for(int i=1;i<=n+k;i++) sz[i]=1,pre[i]=i;
        tot=0;
        for(int i=1;i<=k;i++) {
            if((S>>(i-1))&1) b[++tot]=i,res+=w[i].c;
            now[i]=1;
        }
        now[0]=1;
        int nd,x;
        for(int sum=0;sum<n+tot-1;){
            nd=a[now[0]].w,x=0;
            if(now[0]>=n) nd=1000000000;
            for(int j=1;j<=tot;j++) {
                int u=b[j];
                if(now[u]>n) continue;
                if(w[u].to[now[u]].w<nd) {
                    nd=w[u].to[now[u]].w,x=u;
                }
            }
            if(x==0) {
                // if(a[now[0]].u==0||a[now[0]].v==0) {
                //     cerr<<x<<' '<<now[0]<<' '<<nd<<'\n';
                //     for(int j=1;j<=tot;j++) {
                //         int u=b[j];
                //         cerr<<u<<' '<<now[u]<<'\n';
                //     }
                //     exit(0);
                // }
                bool ok=merge(a[now[0]].u,a[now[0]].v);
                if(ok) res+=a[now[0]].w;
                sum+=ok;
                now[0]++;
            }
            else {
                // if(w[x].to[now[x]].x==0) {
                //     cerr<<x<<' '<<now[x]<<'\n';
                //     exit(0);
                // }
                bool ok=merge(n+x,w[x].to[now[x]].x);
                if(ok) res+=w[x].to[now[x]].w;
                sum+=ok;
                now[x]++;
            }
        }  
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}