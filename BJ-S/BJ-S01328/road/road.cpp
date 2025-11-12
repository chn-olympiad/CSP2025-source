#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15;
const int M=2e6+5;
struct node{
    int u,v,w;
    friend bool operator <(const node &a,const node &b){
        return a.w<b.w;
    }
} g[M];
int cur=0;
inline void add(int u,int v,int w){
    g[++cur]={u,v,w};
    //cout<<u<<' '<<v<<' '<<w<<'\n';
}
int f[N];
int n,k;
inline void init(){
    for (int i=1;i<=n+k;i++){
        f[i]=i;
    }
}
int getfa(int x){
    return x==f[x]?x:f[x]=getfa(f[x]);
}
inline void merg(int u,int v){
    f[getfa(u)]=getfa(v);
}
inline bool insame(int u,int v){
    return getfa(u)==getfa(v);
}
inline int read(){
    int res=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9'){
        res=res*10+c-48;
        c=getchar();
    }
    return res;
}
bool used[15];
inline ll kruskal(){
    init();
    ll res=0;
    for (int i=1;i<=cur;i++){
        int u=g[i].u;
        int v=g[i].v;
        int w=g[i].w;
        if (v>n&&!used[v-n]) continue;
        if (insame(u,v)) continue;
        merg(u,v);
        res+=w;
    }
    return res;
}
ll ans=9e18;
int c[15];
void dfs(int pl,ll cst){
    if (pl>k){
        ans=min(ans,cst+kruskal());
        //cout<<ans<<'\n';
        return;
    }
    if (cst>ans) return;
    dfs(pl+1,cst);
    used[pl]=1;
    dfs(pl+1,cst+c[pl]);
    used[pl]=0;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m;
    n=read();
    m=read();
    k=read();
    while (m--){
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
    for (int i=1;i<=k;i++){
        c[i]=read();
        for (int j=1;j<=n;j++){
            int w=read();
            add(j,n+i,w);
        }
    }
    sort(g+1,g+cur+1);
    if (k==0) cout<<kruskal()<<'\n';
    else{
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
