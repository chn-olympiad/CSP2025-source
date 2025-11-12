#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+20;
const int M = 1e6+20;
int n,m,k;
long long u[M],v[M],w[M],c[15],a[15][N];
struct daolu{
    long long w;
    int v;
};
vector<daolu> edges[N];
struct cmp1{
    bool operator()(daolu p11, daolu p22){
        return p11.w>p22.w;
    };
};
priority_queue<daolu,vector<daolu>,cmp1> pq;
bool vis[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i<=m; ++i){
        scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
        edges[u[i]].push_back({w[i],v[i]});
        edges[v[i]].push_back({w[i],u[i]});
    }
    for(int i = 1; i<=k; ++i){
        scanf("%lld",&c[i]);
        for(int j = 1; j<=n; ++j){
            scanf("%lld",&a[i][j]);
        }
    }
    for(auto i: edges[1]) pq.push(i); vis[1] = true;
    int cnt = 1; long long ans = 0;
    while(true){
        long long x1 = pq.top().w; int x2 = pq.top().v;
        pq.pop();
        if(vis[x2]==true) continue;
        vis[x2] = true; ans += x1; ++cnt;
        if(cnt==n) break;
        for(auto i: edges[x2]){
            pq.push(i);
        }
    }
    cout << ans;
    return 0;
}
