#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,K=11,M=1e6+5;
int n,m,k;
struct edge{int u,v;ll w;}e[M];
vector<edge>key[K];ll cost[K];
inline bool operator<(edge a,edge b){return a.w<b.w;}
struct Izayoi_Sakuya{
    int fa[N+K],sz[N+K];
    int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
    inline void init(){for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;}
    inline bool merge(int u,int v){
        u=find(u),v=find(v);if(u==v)return 0;
        if(sz[u]>sz[v]){swap(u,v);}
        fa[u]=v;sz[v]+=sz[u];
        return 1;
    }
}IS;
ll genshin=0;
void kruskal(){
    sort(e+1,e+m+1);IS.init();int tot=0;
    for(int i=1;i<=m;i++){
        int u=IS.find(e[i].u),v=IS.find(e[i].v);
        if(IS.merge(u,v)){
            key[0].push_back(e[i]);
            genshin+=e[i].w;if(tot==n-1)return;
        }
    }
}
vector<edge>merge(int cnt,ll sum,vector<edge>&a,vector<edge>&b){
    vector<edge>c,d;int ia=0,ib=0;c.clear();d.clear();
    while(ia<a.size()&&ib<b.size()){
        if(a[ia].w>b[ib].w){c.push_back(b[ib++]);}
        else c.push_back(a[ia++]);
    }
    while(ia<a.size()){c.push_back(a[ia++]);}
    while(ib<b.size()){c.push_back(b[ib++]);}
    IS.init();int tot=0;
    for(int i=0;i<c.size();i++){
        int u=IS.find(c[i].u),v=IS.find(c[i].v);
        if(IS.merge(u,v)){
            sum+=c[i].w;tot++;
            d.push_back(c[i]);
            //if(sum>genshin)return e;
            if(tot==n+cnt-1){genshin=min(genshin,sum);return d;}
        }
    }return d;
}
void dfs(int pos,int cnt,ll sum,vector<edge>g){
    //if(g.size()==0){cout<<"WHY";}
    if(g.size()==0||pos==k+1){return;}
    dfs(pos+1,cnt,sum,g);
    dfs(pos+1,cnt+1,sum+cost[pos],merge(cnt+1,sum+cost[pos],g,key[pos]));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){cin>>e[i].u>>e[i].v>>e[i].w;}
    kruskal();
    for(int i=1;i<=k;i++){
        cin>>cost[i];for(int j=1;j<=n;j++){
            int tmp;cin>>tmp;key[i].push_back({i+n,j,tmp});
        }
        sort(key[i].begin(),key[i].end());
    }
    dfs(1,0,0,key[0]);
    cout<<genshin<<endl;
    return 0;
}
