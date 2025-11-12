#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100;
int n,m,k;
vector<pair<int,int>> graph[N];
int c[100];
int father[N];
int dis[N];

int Find(int i) {
    if (father[i] != i) {
        father[i] = Find(father[i]);
    }
    return father[i];
}

int main() {
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }
    for (int i=1;i<=k;i++) {
        cin>>c[i];
        for (int j=1;j<=n;j++) {
            int w;
            cin>>w;
            graph[n + 1].push_back({j , w});
            graph[j].push_back({n + 1 , w});
        }
    }
    memset(dis , 127 , sizeof dis);
    queue<int> myqueue;
    myqueue.push(1);
    dis[1] = 0;
    while(! myqueue.empty()) {
        int u = myqueue.front();
        myqueue.pop();
        for (auto v : graph[u]) {
            if (Find(v.first) != Find(u)) {
                dis[v.first] = dis[u] + v.second;
                father[v.first] = father[u];
            }else {
                dis[v.first] = min(dis[u] + v.second , dis[v.first]);
            }
        }
    }
    cout<<dis[n];
    return 0;
}
