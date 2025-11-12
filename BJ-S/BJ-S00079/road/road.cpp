#include<bits/stdc++.h>
#define int long long
#define pc __builtin_popcountll
using namespace std;
const int N=1e5+17;
const int K=11;
struct Edge{
    int v,w;
};
vector<Edge> E[N+K];
int n,m,k;
int f[N+K];
int c[K],a[K][N],e[K];
inline bool in(int i,int S){
    if(i<=n)return 1;
    return S&(1<<i-n-1);
}
inline int Calc(int S){
    int Ans=0;
    for(int i=1;i<=n;i++)f[i]=1e9+1;
    for(int i=n+1;i<=n+k;i++)f[i]=1e9+1,Ans+=(in(i,S)?c[i-n]:0);
    f[0]=1e9;
    for(int r=1;r<=n+pc(S);r++){
        int u=1;
        if(r!=1){
            u=0;
            for(int i=1;i<=n+k;i++){
                if(i<=n||in(i,S)){
                    if(f[i]<0)continue;
                    if(f[i]<=f[u])u=i;
                }
            }Ans+=f[u];
        }
        f[u]=-1;
        for(auto e:E[u]){
            if(e.v<=n||in(e.v,S))f[e.v]=min(f[e.v],e.w);
        }
    }return Ans;
}inline bool ChkA(){
    for(int u=1;u<=k;u++){
        if(c[u])return 0;
        a[u][0]=1e9;
        for(int i=1;i<=n;i++){
            if(a[u][i]<a[u][e[u]])e[u]=i;
        }if(a[u][e[u]])return 0;
    }return 1;
}inline void slvA(){
    for(int u=1;u<=k;u++){
        for(int i=1;i<=n;i++){
            if(i^e[u]){
                E[e[u]].push_back((Edge){i,a[u][i]});
                E[i].push_back((Edge){e[u],a[u][i]});
            }
        }
    }
    int Ans=0;
    for(int i=1;i<=n;i++)f[i]=1e9+1;
    f[0]=1e9;
    for(int r=1;r<=n;r++){
        int u=1;
        if(r!=1){
            u=0;
            for(int i=1;i<=n;i++){
                if(f[i]<0)continue;
                if(f[i]<=f[u])u=i;
            }Ans+=f[u];
        }
        f[u]=-1;
        for(auto e:E[u])f[e.v]=min(f[e.v],e.w);
    }cout<<Ans<<endl;
    return;
}
int FA[N];
inline int Find(int x){return FA[x]==x?x:FA[x]=Find(FA[x]);}
inline void Merge(int x,int y){
    x=Find(x),y=Find(y);FA[x]=y;
}
struct EEE{
    int u,v,w;
}ED[N*10];
inline bool cmp(EEE x,EEE y){
    return x.w<y.w;
}
inline void Kruskal(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        FA[i]=i;
        for(auto e:E[i]){
            if(i<e.v)ED[++cnt]=(EEE){i,e.v,e.w};
        }
    }sort(ED+1,ED+cnt+1,cmp);
    int Ans=0;
    for(int i=1;i<=cnt;i++){
        if(Find(ED[i].u)!=Find(ED[i].v)){
            Ans+=ED[i].w;Merge(ED[i].u,ED[i].v);
        }
    }cout<<Ans<<endl;return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E[u].push_back((Edge){v,w}),E[v].push_back((Edge){u,w});
    }for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            E[n+i].push_back((Edge){j,a[i][j]});
            E[j].push_back((Edge){n+i,a[i][j]});
        }
    }if(!k){
        Kruskal();
        return 0;
    }
    if(ChkA()){
        slvA();return 0;
    }
    int Ans=1e14;
    for(int i=0;i<(1<<k);i++)Ans=min(Ans,Calc(i));
    cout<<Ans<<endl;return 0;
}