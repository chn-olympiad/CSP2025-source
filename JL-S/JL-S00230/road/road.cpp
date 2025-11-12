#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
typedef pair<int,int> PII;
int n , m , k , ans = INT_MAX;

bool vis[N];
struct Point{
    int c , x , cnt;
};
void bfs(int i , int t,vector<vector<PII>>g){
    queue<Point> q;
    q.push({0,i,1});
    memset(vis,0,sizeof vis);
    while(!q.empty()){
        int u = q.front().x;
        int step = q.front().cnt;
        int C = q.front().c;
        q.pop();
        if(step==t){
            ans = min(ans,C);
        }
        for(auto &edge : g[u]){
            if(!vis[edge.first]) {q.push({edge.second+C,edge.first,step+1});}
            else q.push({edge.second+C,edge.first,step});
        }

    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>k;
    vector<vector<PII>> g(n+1+k);
    for(int i = 1 ; i<=m ; i++){
        int u , v , w;
        cin>>u>>v>>w;
       g[u].push_back({v,w});
       g[v].push_back({u,w});
    }
    for(int i = n+1 ; i<=k+n ; i++){
        int W;
        cin>>W;
        for(int j = 1 ; j<=n ; j++){
            int w;
            cin>>w;
            g[i].push_back({j,W+w});
        }
    }
    for(int i = 0 ; i<=k ; i++)
        bfs(1,n+i,g);
    cout<<ans;
    return 0;
}
