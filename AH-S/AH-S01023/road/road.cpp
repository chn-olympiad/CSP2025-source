#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15][10005];
int test[15];
bool sel[15];
int fa[10015],h[10015];
long long ans=0x3f3f3f3f3f3f3f3f;
void init(){
    for(int i=1;i<=n+k;i++)fa[i]=i,h[i]=1;
}
int root(int u){
    if(u==fa[u])return u;
    return fa[u]=root(fa[u]);
}
bool unit(int u,int v){
    int x=root(u),y=root(v);
    if(x==y)return false;
    if(h[x]>h[y])swap(x,y);
    fa[x]=y,h[y]=max(h[y],h[x]+1);
    return true;
}
struct p{
    int v,w;
};
struct edge{
    int u,v,w;
};
bool cmp(edge a,edge b){
    return a.w<b.w;
}
vector<p> g[10015];
vector<edge> d,tmp,e;
long long solve(){
    long long ret=0,la=0,lb=0;
    tmp.clear();
    for(int i=1;i<=k;i++){
        if(!sel[i])continue;
        ret+=(long long)(c[i][0]);
        for(int j=1;j<=n;j++){
            tmp.push_back({n+i,j,c[i][j]});
        }
    }
    sort(tmp.begin(),tmp.end(),cmp);
    e.clear();
    while(la<d.size()&&lb<tmp.size()){
        if(d[la].w<tmp[lb].w){
            e.push_back(d[la]);
            la++;
        }else{
            e.push_back(tmp[lb]);
            lb++;
        }
    }
    while(la<d.size()){
        e.push_back(d[la]);
        la++;
    }
    while(lb<tmp.size()){
        e.push_back(tmp[lb]);
        lb++;
    }
    init();
    for(int i=0;i<e.size();i++){
        ret+=1LL*unit(e[i].u,e[i].v)*e[i].w;
    }
    return ret;
}
void dfs(int t){
    if(t==k+1){
        ans=min(ans,solve());
        return ;
    }
    sel[t]=1;
    dfs(t+1);
    if(!c[t][0]&&!test[t])return ;
    sel[t]=0;
    dfs(t+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(test,0x3f,sizeof(test));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        d.push_back({u,v,w});
    }
    sort(d.begin(),d.end(),cmp);
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&c[i][j]);
            test[i]=min(test[i],c[i][j]);
        }
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
//Ren5Jie4Di4Ling5%
