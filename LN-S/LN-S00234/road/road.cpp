#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int N=10010;
const int M=1000100;
const int K=11;
int n,m,k,ent=0,val[K],a[K][N],f[N+K];
ll ans=1e18;
struct hhh{
    int u,v,w;
} edge[M],G[N],E[M+K*N];
inline bool cmp(const hhh& x,const hhh& y){
    return x.w<y.w;
}
inline int find(int x){
    return x EQ f[x] ? x : f[x]=find(f[x]);
}
inline bool merge(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu EQ fv){
        return false;
    }
    f[fv]=fu;
    return true;
}
inline void cal(ll cst,int mx){
    for(int t=1;t<=mx;t++){
        f[t]=t;
    }
    sort(E+1,E+ent+1,cmp);
    int num=mx;
    for(int t=1;t<=ent;t++){
        int u=E[t].u,v=E[t].v,w=E[t].w;
        if(!merge(u,v)){
            continue;
        }
        cst+=w;num--;
    }
    if(num EQ 1){
        ans=min(ans,cst);
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0)->ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int t=1;t<=m;t++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[t]={u,v,w};
    }
    for(int i=0;i<k;i++){
        cin>>val[i];
        for(int t=1;t<=n;t++){
            cin>>a[i][t];
        }
    }
    for(int t=1;t<=n;t++){
        f[t]=t;
    }
    sort(edge+1,edge+m+1,cmp);
    int tmp=0;
    for(int t=1;t<=m;t++){
        int u=edge[t].u,v=edge[t].v,w=edge[t].w;
        if(!merge(u,v)){
            continue;
        }
        G[++tmp]=edge[t];
    }
    for(int S=0;S<(1<<k);S++){
        memcpy(E,G,sizeof(G));
        ll need=0;int mx=n;ent=n-1;
        for(int i=0;i<k;i++){
            if(((S>>i)&1) EQ 0){
                continue;
            }
            need+=val[i];mx++;
            for(int t=1;t<=n;t++){
                E[++ent]={mx,t,a[i][t]};
            }
        }
        cal(need,mx);
    }
    cout<<ans<<'\n';
    return 0;
}