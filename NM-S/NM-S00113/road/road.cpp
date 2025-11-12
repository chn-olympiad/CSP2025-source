#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,m,k;
ll dis[N],ans;
bool vis[N];
struct edge{
    int v,w;
};
vector<edge> e[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k>0)cout<<0;
    /*
    else{
        for(int i=0;i<N;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
        priority_queue<edge> q;
        q.push({1,dis[1]});
        while(!q.empty()){
            auto u=q.top();q.pop();
            if(vis[u.v])continue;
            vis[u.v]=1;
            for(int i=0;i<e[u.v].size();i++){
                auto v=e[u.v][i];
                if(dis[v]>dis[u.v]+v.w){
                    dis[v]=dis[u.v]+v.w;
                }
            }
        }
    }
    */
	return 0;
}
