#include <bits/stdc++.h>
using namespace std;

struct node{
    long long u, v, w;
    bool b;
    bool operator<(const node &a) const{
        return w < a.w;
    }
};
long long n, m, k, c[10005], a[15][10005], f[10005], sz[10005], ans=1e18;
vector<node> e1, e;
long long find(long long x){
    if(f[x] == x) return x;
    else return f[x]=find(f[x]);
}
bool merge(long long x, long long y){
    x=find(x);y=find(y);
    if(x == y) return 0;
    if(sz[x] > sz[y]) swap(x, y);
    f[x]=y;
    sz[y]+=sz[x];
    return 1;
}
long long kr(long long p){
    // cout << x << "\n";
    long long ans=0;
    for(long long i=1;i <= n+k;i++){
        f[i]=i;
        sz[i]=1;
    }
    for(node x : e){
        if(x.b == 1 && ((p >> ((x.u-n)-1)) & 1) == 0) continue;
        if(merge(x.u, x.v)){
            ans+=x.w;
        }
    }
    for(long long i=1;i <= k;i++){
        if(((p >> (i-1)) & 1) == 1) ans+=c[i];
    }
    // cout << p << " " << ans << "\n";
    return ans;
}
void dfs(long long i, long long x){
    if(i >= k){
        ans=min(ans, kr(x));
        return;
    }
    dfs(i+1, x);
    dfs(i+1, x+(1 << i));
}
void kr1(){
    for(long long i=1;i <= n;i++){
        f[i]=i;
        sz[i]=1;
    }
    sort(e1.begin(), e1.end());
    for(node x : e1){
        if(merge(x.u, x.v)){
            e.push_back(x);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long u, v, w;
    cin >> n >> m >> k;
    for(long long i=1;i <= m;i++){
        cin >> u >> v >> w;
        e1.push_back({u, v, w, 0});
    }
    kr1();
    for(long long i=1;i <= k;i++){
        for(long long j=0;j <= n;j++){
            if(j == 0) cin >> c[i];
            else cin >> a[i][j];
            if(j >= 1) e.push_back({n+i, j, a[i][j], 1});
        }
    }
    sort(e.begin(), e.end());
    dfs(0, 0);
    cout << ans;
    return 0;
}