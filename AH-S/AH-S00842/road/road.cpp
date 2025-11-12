#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, k, c[N], fa[N], a[15][N];
long long ans = 0;
int ff = 0;
vector<pair<int, int> > g[N];
struct node{
    int u, v;
    long long w;
}e[N];
int Find(int x){
    if(fa[x] == x) return x;
    fa[x] = Find(fa[x]);
    return fa[x];
}
bool cmp(const node& x1, const node& x2){
    return x1.w < x2.w;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1, u, v; i <= m; i++){
        long long w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        int fff = 1;
        if(c[i] != 0) fff = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] != 0) fff = 0;
        }
        if(fff == 1) ff = 1;
    }
    if(ff == 1){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    sort(e + 1, e + m + 1, cmp);
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        if(cnt == n - 1) break;
        int x = e[i].u, y = e[i].v;
        int fx = Find(x);
        int fy = Find(y);
        if(fx == fy) continue;
        fa[fx] = y;
        ans += e[i].w;
        cnt++;
    }
    cout << ans;
    return 0;
}
