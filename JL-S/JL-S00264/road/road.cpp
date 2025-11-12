#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct E{
    int u,v,w,id;
};

inline bool cmp(E u,E v){
    return u.w<v.w;
}

int n,m,k;
E eg[2000001];
int fa[200001],c[200001],siz[200001];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool meg(int u,int v){
    u=find(u),v=find(v);
    if (u==v) return false;
    if (siz[u]>siz[v]) swap(u,v);
    fa[u]=v;
    siz[v]+=siz[u];
    return true;
}

inline ll mst(int s){
    int x=__builtin_popcount(s),cnt=0;
    ll ans=0;
    for (int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
    for (int i=1;i<=m and cnt<=n+x;i++){
        auto [u,v,w,id]=eg[i];
        if (id==0 or (s&(1<<(id-1)))){
            if (meg(u,v)){
                cnt++;
                ans+=w;
            }
        }
    }
    return ans;
}

ll minn=1e18,cost;

void dfs(int dep,int s){
    if (dep>=k+1) return;
    minn=min(minn,mst(s)+cost);
    dfs(dep+1,s);
    cost+=c[dep];
    dfs(dep+1,s|(1<<(dep-1)));
    cost-=c[dep];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        eg[i]={u,v,w,0};
    }
    for (int i=1;i<=k;i++){
        cin>>c[i];
        for (int j=1;j<=n;j++){
            int w;
            cin>>w;
            eg[++m]={n+i,j,w,i};
        }
    }
    sort(eg+1,eg+m+1,cmp);
    dfs(1,0);
    cout<<minn;
    return 0;
}