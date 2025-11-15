#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> edge[10019];
vector<int> connected[19];
bool visited[10019], visited2[10009];
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, c[19], val[19][10009];
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    int tem=0;
    priority_queue<pair<int, int>> pq2;
    pq2.push({0, 1});
    while(!pq2.empty()){
        int ind=pq2.top().second, dis=-pq2.top().first;
        pq2.pop();
        if(!visited2[ind]){
            visited2[ind]=true;
            tem+=dis;
            for(int i=0; i<edge[ind].size(); i++){
                pq2.push({-edge[ind][i].second, edge[ind][i].first});
            }
        }
    }
    for(int i=1; i<=k; i++){
        cin >> c[i];
        for(int j=1; j<=n; j++){
            cin >> val[i][j];
            edge[n+i].push_back({j, val[i][j]});
            edge[j].push_back({n+i, c[i]+val[i][j]});
        }
    }
    int ans=0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {1, -1}});
    while(!pq.empty()){
        int dis=-pq.top().first, ind=pq.top().second.first, par=pq.top().second.second;
        pq.pop();
        if(!visited[ind]){
            // cout << par << " " << ind << '\n';
            visited[ind]=true;
            if(ind>n){
                connected[ind-n].push_back(par);
            }else if(par>n){
                connected[par-n].push_back(ind);
            }
            ans+=dis;
            for(int i=0; i<edge[ind].size(); i++){
                if(!visited[edge[ind][i].first]){
                    pq.push({-edge[ind][i].second, {edge[ind][i].first, ind}});
                }
            }
        }
    }
    for(int i=1; i<=k; i++){
        if(connected[i].size()==1){
            ans-=c[i];
            ans-=val[i][connected[i][0]];
        }
    }
    cout << min(tem, ans);
}