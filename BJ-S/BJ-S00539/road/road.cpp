#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll MOD = 998244353;
int n,m,k;
struct edge{
    ll u,v;
    ll w;
};
vector<edge> e;
vector<int> fa;
bool cmp(edge a,edge b){
    return a.w < b.w;
}
int dfs(int x){
    return (fa[x]==x) ? (x) : (fa[x] = dfs(fa[x]));
}
void merge(int x,int y){
    fa[dfs(x)] = dfs(y);
}
vector<int> dis;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    fa.resize(n+k+1);
    for(int i = 1;i<=n+k;i++){
        fa[i] = i;
    }
    for(int i = 1;i<=n;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        e.push_back({u,v,w});
    }
    int ans = 0;
    for(int i = 1;i<=k;i++){
        int tmp;
        cin >> tmp;
        dis.assign(n+1,0);
        for(int j = 1;j<=n;j++){
            cin >> dis[j];
        }
        for(int j = 1;j<=n;j++){
            for(int p = j+1;p<=n;p++){
                e.push_back({j,p,dis[j]+dis[p]});
            }
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(int i = 0;i<e.size();i++){
        if(dfs(e[i].u)!=dfs(e[i].v)){
            ans += e[i].w;
            merge(e[i].u,e[i].v);
            //cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w <<  '\n';
        }
    }
    cout << ans;
    return 0;
}
/*
g++ A.cpp -o A
./A
*/