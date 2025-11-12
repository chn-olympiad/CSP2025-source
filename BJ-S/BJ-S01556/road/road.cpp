#include <bits/stdc++.h>
using namespace std;
using ill = long long;
using pii = pair<int,ill>;
const int N = 1e4+5;
const int M = 1e6+5;
const int K = 15;
int n,m,k;
ill c[K];
ill a[K][N];
ill ans;
vector<pii> e[N],g[N],f[N];
struct Edge{
    int u,v;
    ill w;
    bool operator<(const Edge &x) const{
        return w < x.w;
    }
    bool operator>(const Edge &x) const{
        return w > x.w;
    }
};
priority_queue<Edge,vector<Edge>,greater<Edge>> q;
int fa[N+K];
int find_fa(int x){
    if(x == fa[x])
        return x;
    return fa[x] = find_fa(fa[x]);
}
void kruskral(){
    for(int i=1;i<=n;i++)
        fa[i] = i;
    for(int i=1;i<=n;i++)
        for(auto p:e[i])
            if(i < p.first)
                q.push({i,p.first,p.second});
    while(!q.empty()){
        Edge p = q.top();
        q.pop();
        int u = p.u, v = p.v; ill w = p.w;
        if(find_fa(u) == find_fa(v))
            continue;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        fa[find_fa(u)] = find_fa(v);
    }
}
void kruskral_t(ill &res){
    for(int i=1;i<=n;i++)
        for(auto p:f[i])
            if(i < p.first)
                q.push({i,p.first,p.second});
    while(!q.empty()){
        Edge p = q.top();
        q.pop();
        int u = p.u, v = p.v; ill w = p.w;
        if(find_fa(u) == find_fa(v))
            continue;
        res += w;
        fa[find_fa(u)] = find_fa(v);
    }
}
ill solve(int t){
    ill res = 0ll;
    while(!q.empty())
        q.pop();
    for(int i=1;i<=n+k;i++)
        fa[i] = i;
    for(int i=1;i<=n;i++)
        f[i] = g[i];
    for(int i=0;i<k;i++){
        if(t & (1 << i)){
            res += c[i+1];
            for(int j=1;j<=n;j++)
                f[j].push_back({i+n+1,a[i+1][j]});
        }
    }
    kruskral_t(res);
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        ill w;
        scanf("%d%d%lld",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    }
    kruskral();
    for(int i=1;i<=n;i++)
        for(auto j:g[i])
            ans += j.second;
    ans >>= 1ll;
    for(int t=1;t<=((1<<k)-1);t++)
        ans = min(ans,solve(t));
    printf("%lld\n",ans);
    return 0;
}
