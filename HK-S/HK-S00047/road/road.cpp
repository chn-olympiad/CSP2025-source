#include <bits/stdc++.h>
using namespace std;
int main(){
  ifstream f("road.in");
  ofstream g("road.out");
  long long n,m,k,u,v,w,c,goal,temp,INF=1000000000000000000;
  f>>n>>m>>k;
  vector<vector<pair<long long,long long>>> to(n+k+1);
  vector<long long> cost(n+k+1, INF);
  vector<long long> used(n+k+1);
  for (int i=0;i<m;i++){
    f>>u>>v>>w;
    to[u].push_back(make_pair(v,w));
    to[v].push_back(make_pair(u,w));
  }
  for (int i=0;i<k;i++){
    f>>c;
    for (int j=0;j<n;j++){
      f>>w;
      to[j+1].push_back(make_pair(n+i+1,w+c));
      to[n+i+1].push_back(make_pair(j+1,w+c));
    }
  }
  priority_queue<pair<long long, long long>> pq;
  cost[1]=0;
  used[1]=1;
  for (int i=0;i<to[1].size();i++){
    goal=to[1][i].first;
    if (cost[goal] > to[1][i].second){
      cost[goal] = to[1][i].second;
      pq.push(make_pair(INF-cost[goal],goal));
    }
  }
  while (pq.size()>0){
    temp=pq.top().second;
    cout<<temp<<" "<<cost[1]<<" "<<cost[2]<<" "<<cost[3]<<" "<<cost[4]<<endl;
    if (used[temp]==0){
        used[temp]=1;
        for (int i=0;i<to[temp].size();i++){
            if (used[to[temp][i].first]==0){
                if (cost[to[temp][i].first] > cost[temp] + to[temp][i].second){
                    cost[to[temp][i].first] = cost[temp] + to[temp][i].second;
                    pq.push(make_pair(INF-cost[to[temp][i].first] , to[temp][i].first));
                }
            }
        }
    }
    pq.pop();
  }
  long long ans=0;
  for (int i=1;i<=n;i++){
    ans = max(ans, cost[i]);
  }
  g<<ans;
}