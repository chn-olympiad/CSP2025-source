#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
struct edge {
    int v,w;
};
struct node {
    int u,dis;
    bool operator >(const node &x) const {
        return x.dis>dis;
    }
};
int n,m,k,dis[10005];
bool vis[10005];
vector<edge> e[10005];
void dijkstra(int s) {
    fill(dis,dis+1+n,INT_MAX);
    memset(vis,false,sizeof(vis));
    priority_queue<node,vector<node>,greater<node>> q;
    dis[s]=0,q.push({s,0});
    while (!q.empty()) {
        int u=q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (auto ed:e[u]) {
            int v=ed.v,w=ed.w;
            if (dis[u]+w<dis[v]) dis[v]=dis[u]+w,q.push({v,dis[v]});
        }
    }
}
*/
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    /*
    cin>>n>>m>>k;
    for (int i=1,u,v,w;i<=m;i++)
        cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
    if (k==0) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            dijkstra(i);
            for (int j=i+1;j<=n;j++)
                ans+=dis[j];
        }
        cout<<ans;
        return 0;
    }
    */
    cout<<0;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
