#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5,M=1e6+5;
const ll inf=1e17;
int n,m,k;
ll ans=inf;
int a[20][N],c[N],fa[N],siz[N],vis[N];
struct edge{
    int u,v,w;
}e[M],ne[N];
vector<edge>v;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
struct Dsu{
    void init(){
        for(int i=1;i<=n+k;i++)  fa[i]=i,siz[i]=1;
    }
    int find(int x){
        if(fa[x]==x)  return x;
        return fa[x]=find(fa[x]);
    }
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)  return 0;
        if(siz[x]>siz[y])  swap(x,y);
        siz[y]+=siz[x];
        fa[x]=y;
        return 1;
    }
}dsu;
void kul1(){
    int cnt=0;
    sort(e+1,e+1+m,cmp);
    dsu.init();
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(dsu.merge(u,v)){
            ne[++cnt]={u,v,w};
        }
        if(cnt==n-1)  return;
    }
}
void kul2(int g,ll res){
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    dsu.init();
    for(auto i:v){
        int u=i.u,v=i.v,w=i.w;
        if(dsu.merge(u,v)){
            res+=w;
            cnt++;
        }
        if(cnt==n+g-1){
            ans=min(ans,res);
        }
        if(res>ans)  return;
    }
}
void dfs(int x){
    if(x>k){
        v.clear();
        for(int i=1;i<=n-1;i++){
            v.push_back(ne[i]);
        }
        int g=0;
        ll res=0;
        for(int i=1;i<=k;i++){
            if(!vis[i])  continue;
            for(int j=1;j<=n;j++){
                v.push_back({n+i,j,a[i][j]});
            }
            res+=c[i];
            g++;
        }
        kul2(g,res);
        return;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i]={u,v,w};
    }
    kul1();
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}