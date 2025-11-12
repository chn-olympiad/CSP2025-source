#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+20,K=20,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k;
ll a[K][N],c[K],res,ans=inf;
bool A=1;
struct edge{
    int u,v;
    ll w;
    bool operator<(edge b){
        return w<b.w;
    }
};
vector<edge>e1,e2;
struct bc{
    int fa[N],siz[N];
    void build(){
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
            siz[i]=1;
        }
    }
    int gf(int a){
        if(fa[a]==a)return a;
        return fa[a]=gf(fa[a]);
    }
    void hb(int a,int b){
        a=gf(a);b=gf(b);
        if(gf(a)==gf(b))return;
        if(siz[a]>siz[b])swap(a,b);
        fa[a]=b;
        siz[b]+=siz[a];
    }
}bc;
void solve1(){
    bc.build();
    sort(e2.begin(),e2.end());
    for(auto i:e2){
        if(bc.gf(i.u)==bc.gf(i.v)){
            continue;
        }
        bc.hb(i.u,i.v);
        res+=i.w;
    }
}
void solve2(){
    for(int i=0;i<(1<<k);i++){
        res=0;
        e2=e1;
        for(int j=1;j<=k;j++){
            if(!(i&(1<<(j-1))))continue;
            for(int p=1;p<=n;p++){
                e2.push_back({p,n+j,a[j][p]});
            }
            res+=c[j];
        }
        solve1();
        ans=min(ans,res);
    }
    cout<<ans;
}
void solve3(){
    e2=e1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            e2.push_back({j,n+i,a[i][j]});
        }
    }
    solve1();
    cout<<res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e1.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])A=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(A)solve3();
    else solve2();
    return 0;
}