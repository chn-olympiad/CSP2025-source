#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+100;
int n,m,k;
ll a[15][N],c[15];
struct edge{
    ll u,v,w;
    int id;
};
vector<edge> e;
void add(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;++j){
            e.push_back({j,n+i,a[i][j],i});
        }
    }
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int fa[N];
int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}
int u,v,w,ufa,vfa;
bool vis[15];
ll calc(int x){
    memset(vis,false,sizeof vis);
    vis[0]=true;
    ll res=0;
    for(int i=0;i<k;++i){
        if(x&(1<<i)){
            vis[i+1]=true;
            res+=c[i+1];
        }
    }
    for(int i=1;i<N;++i){
        fa[i]=i;
    }
    for(edge t:e){
        u=t.u,v=t.v,w=t.w;
        if(vis[t.id]==false){
            continue;
        }
        ufa=find(u);
        vfa=find(v);
        if(ufa==vfa){
            continue;
        }
        res+=w;
        fa[ufa]=vfa;
    }
    return res;
}
vector<edge> tmp_e;
void get_e(){
    sort(e.begin(),e.end(),cmp);
    for(register int i=1;i<N;++i){
        fa[i]=i;
    }
    for(edge t:e){
        u=t.u,v=t.v,w=t.w;
        ufa=find(u);
        vfa=find(v);
        if(ufa==vfa){
            continue;
        }
        fa[ufa]=vfa;
        tmp_e.push_back({u,v,w});
    }
    e=tmp_e;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin >>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;++i){
        cin >>c[i];
        for(int j=1;j<=n;++j){
            cin >>a[i][j];
        }
    }
    get_e();
    add();
    sort(e.begin(),e.end(),cmp);
    ll ans=9e18;
    for(int i=0;i<(1<<k);++i){
        ans=min(ans,calc(i));
    }
    cout <<ans<<"\n";
    return 0;
}
