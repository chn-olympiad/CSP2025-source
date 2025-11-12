#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
const ll INF = 1e18;
int n, m, k, c[K];
struct Node{
    int u, v;ll w;
    bool operator <(Node &x){
        return w < x.w;
    }
}e[M << 1];
ll ans = INF;
int f[N], sz[N];
int fa(int u){return f[u] == u ? u : f[u] = fa(f[u]);}
void get(int s){
    ll nw = 0;
    int p = n;
    for(int i = 1;i <= k;i++)if(s & (1 << i - 1))nw += c[i], p++;
    for(int i = 1;i <= n + k;i++)f[i] = i, sz[i] = 1;
    for(int i = 1;i <= m;i++){
        if(e[i].u > n && !(s & (1 << e[i].u - n - 1)))continue;
        int fu = fa(e[i].u), fv = fa(e[i].v);
        if(fu != fv){
            if(sz[fu] > sz[fv])swap(fu, fv);
            f[fu] = fv;
            p--;
            nw += e[i].w;
        }
        if(nw > ans)return;
        if(p <= 1)break;
    }
    ans = min(ans, nw);
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            int w;
            cin >> w;
            e[++m] = {i + n, j, w};
        }
    }
    sort(e + 1, e + m + 1);
    for(int s = 0;s < (1 << k);s++){
        get(s);
    }
    cout << ans;
    return 0;
}