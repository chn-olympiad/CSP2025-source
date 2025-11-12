#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6+10;
struct node{
    int u,v,w;
};
bool cmp(node a,node b){
    return a.w < b.w ;
}
vector <node> G;
bool vis[N] = {} ;
int o[N] = {} ;
int n,m,k;
int f[N] = {} ;
int getfa(int u){
    return f[u] = (f[u]==u?u:getfa(f[u]));
}
int minsch(){
    int res = 0;
    sort(G.begin(),G.end(),cmp);
    for(auto i : G){
        int fa = getfa(i.u);
        int fb = getfa(i.v);
        if(fa==fb) continue;
        f[fa] = fb ;
        res += i.w;
    }
    return res ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >>m >> k;
    for(int i = 1 ; i <= n+k ; i ++)
        f[i] = i ;
    for(int i = 1 ; i <= m ; i ++){
        int u,v,w;
        cin >> u >> v >> w ;
        G.push_back({u,v,w});
    }
    for(int i = 1 ; i <= k ; i ++){
        cin >> o[i];
        for(int j = 1 ; j <= n ; j ++){
            int t ;
            cin >> t ;
            G.push_back({n+i,j,t});
        }
    }
    cout << minsch();
    return 0 ;
}
