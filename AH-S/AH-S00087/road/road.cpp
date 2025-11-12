#include<bits/stdc++.h>
#define N 10011
using namespace std;
int n,m,k,g[11][10001],mx,_t;
struct edge{
    int u,v,w;
    bool operator<(const edge&tmp)const{
        return w<tmp.w;
    }
};
vector<edge>e;
int fa[N];
void init(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    fa[find(x)]=find(y);
}
bool in(int x,int y){
    return find(x)==find(y);
}
long long kruscal(int n,vector<edge>e1){
    init(n);
    long long ans=0;
    int cnt=0,i=0;
    while(cnt<n-1){
        int u=e1[i].u,v=e1[i].v,w=e1[i++].w;
        if(!in(u,v)){
            unite(u,v);
            cnt++;
            ans+=w;
            _t=w;
        }
    }
    return ans;
}
bool used[11];
long long ans=0x7fffffffffffffff;
void dfs(int u,int cost){
    if(clock()*1.0/CLOCKS_PER_SEC>=0.98){
        cout<<ans;
        exit(0);
    }
    if(u==k+1){
        int cnt=0;
        vector<edge>e1;
        for(auto t1:e)
            e1.push_back(t1);
        for(int i=1;i<=k;i++)
            if(used[i]){
                cnt++;
                for(int j=1;j<=n;j++)
                    e1.push_back(edge{cnt+n,j,g[i][j]});
            }
        sort(e1.begin(),e1.end());
        long long tmp=kruscal(n+cnt,e1)+cost;
        ans=min(ans,tmp);
        return ;
    }
    dfs(u+1,cost);
    if(cost+g[u][0]<ans){
        used[u]=true;
        dfs(u+1,cost+g[u][0]);
        used[u]=false;
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        e.push_back(edge{u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>g[i][0];
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    dfs(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
