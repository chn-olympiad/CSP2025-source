#include <bits/stdc++.h>
using namespace std;
int n, m, k, f[10005];
int u, v, w;
long long ans = 0;
struct node{
    int u, v, w;
};
vector<node> maap;
bool cmp(node a, node b){
    return a.w < b.w;
}
int fiiiind(int x){
    if (f[x] == x) return x;
    return f[x] = fiiiind(f[x]);
}
void merrrrge(int x, int y){
    f[fiiiind(x)] = f[y];
}
void zxscs(){
    for (int i = 1; i <= n; i++) f[i] = i;
    int cccccnt = 0;
    for (auto x : maap){
        u = x.u, v = x.v, w = x.w;
        if (fiiiind(u) == fiiiind(v)) continue;
        ans += w;
        merrrrge(u, v);
        cccccnt++;
        if (cccccnt == n - 1) return;
//        cout << ans << "\n";
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        maap.push_back({u, v, w});
    }
    if (k == 0){
        sort(maap.begin(), maap.end(), cmp);
        zxscs();
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= k; i++){
        int florian;
        cin >> u;
        florian = ++n;
        for (int j = 1; j <= n - i; j++){
            cin >> w;
            maap.push_back({florian, j, w});
        }
    }
    sort(maap.begin(), maap.end(), cmp);
    zxscs();
    cout << ans;
    return 0;
}
