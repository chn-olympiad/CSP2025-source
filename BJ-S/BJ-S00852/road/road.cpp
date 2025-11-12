#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+7,M=1e6+7,K=17;
int n,m,k;
struct edge{
    int u,v,w,id;
}e[M<<2];
ll ans=LLONG_MAX,res,c[K];
int fa[N<<1],siz[N<<1];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void merge(int u,int v){
    if(siz[u]<siz[v])swap(u,v);
    siz[u]+=siz[v],fa[v]=u;
}
vector<int>eid[K];
bool ban[M<<2];
inline void solve(int S){
    res=0;
    for(int i=1;i<=m;i++)ban[i]=0;
    for(int i=1;i<=k;i++){
        if(!(S&(1<<(i-1)))){
            for(int id:eid[i])ban[id]=1;
        }else res+=c[i];
    }
    for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        if(ban[e[i].id])continue;
        int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
        if(u==v)continue;
        res+=w;
        merge(u,v);
    }
    ans=min(ans,res);
}
bool tskA=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].id=i;
    }
    for(int i=1;i<=k;i++){
        int a;
        cin>>c[i];
        if(c[i]>0)tskA=1;
        for(int j=1;j<=n;j++){
            cin>>a;
            ++m;
            e[m]={i+n,j,a,m};
            eid[i].push_back(m);
        }
    }
    sort(e+1,e+1+m,[](const edge &a,const edge &b){
        return a.w<b.w;
    });
    if(k<=5){
        for(int S=0;S<(1<<k);S++){
            solve(S);
        }
    }else{
        if(!tskA)solve((1<<k)-1);
        else{
            solve(0);
            mt19937 rnd(time(nullptr));
            for(int c=1;c<=480;c++){
                int S=rnd()%(1<<k);
                solve(S);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}