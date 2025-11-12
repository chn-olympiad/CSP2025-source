#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace Solution {
    constexpr int MAX_N = 1e4+50;
    constexpr int MAX_M = 2e6+10;
    constexpr int MAX_K = 15;

    struct Edge {
        int u,v;
        ll w;
        bool operator<(Edge &x) {
            return w<x.w;
        }
    } graph[MAX_M],tree[MAX_N],tmp[MAX_M];

    int fa[MAX_N];
    void init(int n) {
        for(int i=1;i<=n;++i) fa[i] = i;
    }
    int find(int x) {
        return x==fa[x]?x:(fa[x]=find(fa[x]));
    }
    void merge(int x,int y) {
        fa[find(x)] = find(y);
    }

    int n,m,k;
    ll c[MAX_K],a[MAX_K][MAX_N];
    int cnt = 0;

    ll solve_s(int stat) {
        ll ans = 0;
        bitset<MAX_K> b(stat);
        for(int i=1;i<=k;++i) {
            if(b[i-1]) ans += c[i];
        }

        for(int i=1;i<n;++i) tmp[i] = tree[i];
        int curr_m = n-1;
        for(int i=1;i<=k;++i) {
            if(!b[i-1]) continue;

            for(int j=1;j<=n;++j) {
                tmp[++curr_m] = {n+i,j,a[i][j]};
            }
        }
        sort(tmp+1,tmp+curr_m+1);
        init(n+k);
        for(int i=1;i<=curr_m;++i) {
            if(find(tmp[i].u)==find(tmp[i].v)) {
                continue;
            }
            merge(tmp[i].u,tmp[i].v);
            ans += tmp[i].w;
        }

        return ans;
    }

    void solve() {
        cin>>n>>m>>k;
        for(int i=1;i<=m;++i) {
            int u,v,w;
            cin>>u>>v>>w;
            graph[i] = {u,v,w};
        }
        for(int i=1;i<=k;++i) {
            cin>>c[i];
            for(int j=1;j<=n;++j) cin>>a[i][j];
        }
        
        sort(graph+1,graph+m+1);
        init(n);
        ll min1 = 0;
        for(int i=1;i<=m;++i) {
            if(find(graph[i].u)==find(graph[i].v)) {
                continue;
            }
            merge(graph[i].u,graph[i].v);
            tree[++cnt] = graph[i];
            min1 += graph[i].w;
            // cout<<min1<<'\n';
        }

        // cout<<min1<<'\n';

        ll ans = 1e15;

        for(int stat=0;stat<(1<<k);stat++) {
            ll curr;
            ans = min(ans,curr=solve_s(stat));
            // cout<<curr<<'\n';
        }

        cout<<ans<<'\n';
    }
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    for(int t=1;t<=T;++t) {
        Solution::solve();
    }
    return 0;
}