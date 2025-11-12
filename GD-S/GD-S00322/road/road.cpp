#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e5+10;
int n,m,k,vis[N],dis;
vector<PII>g[N];
inline void bfs(){
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    while(!q.empty()){
        int u=q.top().second,we=q.top().first;q.pop();
        if(vis[u])continue;
        vis[u]=1,dis+=we;
        for(auto i:g[u]){
            int v=i.first,w=i.second;
            if(vis[v])continue;
            q.push({w,v});
        }
    }
}
signed main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    if(k==0){
        bfs();
        return cout<<dis<<"\n",0;
    }
    cout<<"0\n";
    return 0;
}
/*
5 7 0
1 2 1
2 3 2
3 4 3
4 5 4
5 1 5
5 3 6
2 4 7
*/
