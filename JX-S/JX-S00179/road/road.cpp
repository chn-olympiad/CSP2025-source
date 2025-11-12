#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,ans;
int a[12][10020];
int c[12];
int dis[10020];
bool vis[10020];
vector<pair<int,int> >g[10020];
struct node{
    int x,l;
    bool operator <(node a) const{
        return l>a.l;
    }
};
void dij(){
    priority_queue<node>q;
    q.push({1,0});
    while(!q.empty()){
        node p=q.top();
        q.pop();
        if(vis[p.x])continue;
        vis[p.x]=1;
        ans+=p.l;
        //cout<<p.x<<" "<<p.len<<endl;
        for(auto v:g[p.x]){
            q.push({v.first,v.second});
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            g[n+i].push_back({j,a[i][j]});
            g[j].push_back({n+i,a[i][j]});
        }
    }
    dij();
    cout<<ans;
    return 0;
}
/*
7 9 0
1 2 2
2 3 1
2 4 3
3 5 1
3 6 2
4 6 1
5 6 1
5 7 3
6 7 2
*/
