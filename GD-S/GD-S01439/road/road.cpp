#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
using vint = vector<int>;
using pii = pair<int,int>;
struct union_find{
    vint fa,siz;
    union_find(int n){
        fa.resize(n+1);
        siz.assign(n+1,1);
        iota(fa.begin(),fa.end(),0);
    }
    int find_root(int n){
        if(fa[n] == n){
            return n;
        }
        return fa[n]=find_root(fa[n]);
    }
    void connect(int x,int y){
        x = find_root(x);
        y = find_root(y);
        if(siz[x] > siz[y]) swap(x,y);
        fa[x]=y;
        siz[y] += siz[x];
    }
    bool is(int x,int y){
        return find_root(x) == find_root(y);
    }
};
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<tuple<int,int,int>> all(m);
    for(auto& [w,u,v]:all){
        cin >> u >> v >> w;
    }
    // pre build mini tree
    union_find uf(n);
    sort(all.begin(),all.end());
    int ans = 4e18;
    vector<tuple<int,int,int>> build;
    for(auto [w,u,v]:all){
        if(uf.is(u,v)) continue;
        uf.connect(u,v);
        build.emplace_back(w,u,v);
    }
    vector<vint> road(k,vint(n + 1));
    vint cost(k);
    for(int i =0;i<k;i++){
        cin >> cost[i];
        for(int j=1;j<=n;j++){
            cin >> road[i][j];
        }
    }
    int mask = (1 << k);
    for(int i = 0;i<mask;i++){
        int ret = 0;
        vector<tuple<int,int,int>> now = build;
        for(int pos = 0;pos<k;pos++){
            if((i >> pos) & 1){
                ret+=cost[pos];
                for(int j =1;j<=n;j++){
                    now.emplace_back(road[pos][j],n + pos + 1,j);
                }
            }
        }
        union_find uf(n + k + 1);
        sort(now.begin(),now.end());
        for(auto [w,u,v]:now){
            if(uf.is(u,v)) continue;
            uf.connect(u,v);
            ret+=w;
            if(ret > ans) break;
        }
        ans = min(ans,ret);
    }
    cout << ans << endl;
    return 0;
}
