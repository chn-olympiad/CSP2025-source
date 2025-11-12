#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+1, K = 11;
int n, m, k;
ll ans=1e18, c[K], a[K][N];
struct Node{
    int u, v;
    ll w;
    bool operator<(const Node &i) const {return w<i.w;}
};
vector<Node> e, add[K];
typedef pair<Node, int> pni;
priority_queue<pni, vector<pni>, greater<pni>> pq;
struct DSU{
    int fa[N+K], sz[N+K];
    void init(int n){for(int i=1;i<=n;i++) fa[i] = i, sz[i] = 1;}
    int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
    bool merge(int u, int v){
        int s = getfa(u), t = getfa(v);
        if (s==t) return 0;
        if (sz[s] <= sz[t]) fa[s] = t, sz[t] += sz[s];
        else fa[t] = s, sz[s] += sz[t];
        return 1;
    }
} dsu;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    e.reserve(m);
    for(int i=0;i<=k;i++) add[i].reserve(n);
    while(m--){
        int u, v; ll w;
        cin>>u>>v>>w;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end());
    // kruskal
    dsu.init(n);
    for(auto node:e){
        int u = node.u, v = node.v;
        ll w = node.w;
        if(dsu.merge(u, v)) add[0].push_back({u, v, w});
        else continue;
        //if (add[0].size()==n-1) break;
    }
    //return 0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            add[i].push_back({n+1, j, a[i][j]});
        }
        sort(add[i].begin(), add[i].end());
    }
    //for(int i=0;i<=k;i++) cout<<add[i].size()<<' ';cout<<'\n';
    for(int msk=0;msk<(1<<k);msk++){
        dsu.init(n+k);
        while(!pq.empty()) pq.pop();
        int cnt = n - 1;
        ll sum = 0;
        vector<int> ids, pos(k+1,0);
        ids.reserve(k+1);
        ids.push_back(0);
        for(int j=0;j<k;j++){
            if (msk & (1<<j)){
                cnt++;
                sum += c[j+1];
                ids.push_back(j+1);
            }
        }
        if (sum>ans) continue;
        for(auto id:ids){
            pq.push({add[id][0], id});
        }
        while(!pq.empty() && sum<ans){
            auto o = pq.top();
            Node node = o.first;
            int id = o.second;
            int u = node.u, v = node.v;
            ll w = node.w;
            pq.pop();
            if (dsu.merge(u, v)){
                sum+=w;
                cnt--;
                if(cnt==0) break;
            }
            pos[id]++;
            if (pos[id]<add[id].size()) pq.push({add[id][pos[id]], id});
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
