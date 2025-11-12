#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+8;
const int INF = 0x3f3f3f3f;
int n,m,k,cnt,ans;
int dis[N];
int chos[1000006];
struct node{
    int v,w;
    bool operator <(const node &rhs) const{
        return rhs.w < w;
    }
};

vector <node> adj[N];

void Dijkstra(int s){
    cnt = 0;
    priority_queue <node> q;

    q.push({s,0});
    memset(chos,0,sizeof(chos));
    memset(dis,INF,sizeof(dis));
    dis[s] = 0;
    while(q.size()){
        node cur = q.top();
        q.pop();
        int u = cur.v,w = cur.w;

        for(int i = 0; i < adj[u].size();i++){
            int v = adj[u][i].v,aw = adj[u][i].w;
            if(dis[v] > w+aw){

                dis[v] = w+aw;
                chos[++cnt] = aw;
                q.push({v,dis[v]});
            }
        }
    }

    return ;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;

    for(int i = 1,u,v,w; i <= m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int maxn = 0;
    if(k == 0){
        Dijkstra(1);
        for(int i = 1; i <= n; i++){
            maxn = max(maxn,dis[i]);
        }
    }

    for(int i = 1; i <= cnt; i++){
        if(chos[i]> maxn) chos[i] = 0;
    }

    for(int i = 1; i <= cnt; i++){
        ans+=chos[i];
    }

    cout << ans;

    return 0;
}
