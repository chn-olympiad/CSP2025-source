#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=2e4+5;
#define int long long
int n,m,k,c[11][MAXLEN],bui[MAXLEN]={-1};
struct edge{
    int to,w;
};
vector<edge> g[MAXLEN];
inline void addedge(int u,int v,int w){
    g[u].push_back((edge){v,w});
    g[v].push_back((edge){u,w});
}

struct node{
    int id,dis;
    inline bool operator < (const node &rhs) const{
        return dis>rhs.dis;
    }
};

int dis[MAXLEN];
bool done[MAXLEN];
priority_queue<node> q;
inline int prim(int s){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(!q.empty()) q.pop();
    memset(dis,0x3f,sizeof(dis));
    memset(done,0,sizeof(done));
    q.push((node){s,0});
    dis[s]=0;
    while(!q.empty()){
        node u=q.top();
        q.pop();
        if(done[u.id]) continue;
        done[u.id]=true;
        for(int i=0;i<g[u.id].size();i++){
            edge y=g[u.id][i];
            if(done[y.to]) continue;
            if(dis[y.to]>y.w){
                dis[y.to]=y.w;
                q.push((node){y.to,y.w});
            }
        }

    }int ans=0;
    for(int i=1;i<=n;i++){
        //printf("\n%d\n",dis[i]);
        ans+=dis[i];
    }if(dis[n+1]<0x3f3f3f3f3f3f3f3f) ans+=dis[n+1];
    return ans;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        addedge(u,v,w);
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){cin>>c[i][j];
        }
    }int mi=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<=(1ll<<k)-1;i++){
        //printf("%d\n",i);
        int add=0;
        g[n+1].clear();
        memset(bui,0x3f,sizeof(bui));
        for(int j=1;j<=k;j++){
            if(i&(1ll<<(j-1))){
                add+=c[j][0];
                for(int o=1;o<=n;o++){
                    bui[o]=min(bui[o],c[j][o]);
                }
            }
        }
        for(int j=1;j<=n;j++){
            //printf("%d ",bui[j]);
            addedge(n+1,j,bui[j]);
        }
        mi=min(mi,prim(1)+add);
        //printf("%d %d %d\n",i,prim(1),add);
        for(int j=1;j<=n;j++){
            g[j].pop_back();
        }
    }cout<<mi;
    return 0;
}
