#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k;
struct node{
    ll v,w;
};
vector<node>g[10005];
struct road{
    ll id,val;
    bool operator<(const road& ano)const{
        return val<ano.val;
    }
};
ll bfs(int s){
    priority_queue<road>q;
    q.push({s,0});
    ll dis[n+5];
    ll res=0;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    while(q.size()){
        auto u=q.top();
        q.pop();
        if(u.val!=dis[u.id]){
            continue;
        }
        res+=dis[u.id];
        for(auto i:g[u.id]){
            ll v=i.v,w=i.w;
            if(dis[v]>dis[u.id]+w){
                dis[v]=dis[u.id]+w;
                q.push({v,dis[v]});
            }
        }
    }
    return res;
}
int main() {
	// freopen("road.in","r",stdin);
	// freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    if(k==0){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,bfs(i));
        }
        cout<<ans;
        return 0;
    }
	return 0;
}