#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
const int N=2e4+10;
int n,m,k;
struct node{
    int x,y,w;
}a[MAXN],e[N],ed[MAXN];
bool cmp(node x,node y){
    return x.w<y.w;
}
struct DSU{
    int fa[MAXN],sz[MAXN];
    void init(){
        for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
    }
    int find(int x){
        return (fa[x]==x?x:(fa[x]=find(fa[x])));
    }
    bool merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return 0;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y]=x;sz[x]+=sz[y];return 1;
    }
}dsu;
ll ans;
int g[11][N],w[11];
void solve(int x){
    ll sum=0;int tmp=0;int bot=0;
    for(int i=k-1;i>=0;i--) {
        if(x>>i&1) {
            sum+=w[i];bot++;
            for(int j=1;j<=n;j++) ed[++tmp]=(node){i+n+1,j,g[i][j]};
        }
    }
    for(int i=1;i<n;i++) ed[++tmp]=e[i];
    stable_sort(ed+1,ed+1+tmp,cmp);
    dsu.init();int num=0;
    for(int i=1;i<=tmp;i++){
        if(dsu.merge(ed[i].x,ed[i].y)){
            sum+=ed[i].w;++num;
            if(sum>=ans) break;
            if(num==n+bot-1){
                break;
            }
        }
    }
    ans=min(ans,sum);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>m>>k;int tot=0;
    for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].w;
    dsu.init();
    for(int i=0;i<k;i++){
        cin>>w[i];
        for(int j=1;j<=n;j++) cin>>g[i][j];
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(dsu.merge(a[i].x,a[i].y)){
            ans+=a[i].w;e[++tot]=a[i];
            if(tot==n-1) break;
        }
    }
    for(int i=1;i<(1<<k);i++) solve(i);
    cout<<ans;
    return 0;
}