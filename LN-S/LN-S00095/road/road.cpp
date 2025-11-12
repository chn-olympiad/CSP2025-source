#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

struct Node{
    int dis;
    int u;
};

struct Edge{
    int v;
    int w;
};

std::vector<std::vector<Edge> > e;
int n,m,k;
long long minans = 0x3f3f3f;
bool vis[10005];

void dfs(int d, long long ans);

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    int u,v,w;
    e.reserve(1000020);

    for(int i = 0;i<m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v, w});
    }
    int c;
    for(int i = 0;i<k;i++){
        cin>>c;
        for(int j = 0;j<n;j++){
            cin>>w;
            e[n+i].push_back({j+1, w+c});
        }
    }
    dfs(1,0);
}

void dfs(int d, long long ans){
    if(d == n){
        if(minans > ans) maxans = ans;
        return;
    }
    for(auto ed : e){
        int v = ed.v,w = ed.w;
        if(!vis[v]){
            dfs(d+1, ans+w);
        }
    }
}
