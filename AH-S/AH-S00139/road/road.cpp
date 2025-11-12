#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int f[10004], c[10004];
struct node{
    int u, v;
    ll w;
};
vector <node> e;
bool cmp(node a, node b){    return a.w < b.w; }
int find(int v){
    if(f[v] == v)   return v;
    f[v] = find(f[v]);
    return f[v];
}
bool hebing(int x, int y){
    int a = find(x), b = find(y);
    if(a != b){
        f[b] = a;
        return true;
    }
    return false;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0;i <= n;i++)   f[i] = i;
    for(int i = 0;i < m;i++){
        int u, v; ll w;    cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            ll w;  cin >> w;
            e.push_back({i, j, w});
        }
    }
    ll ans = 0;
    sort(e.begin(), e.end(), cmp);
    int cnt = 0, i = 0;
    while(cnt < n && i < m){
        if(hebing(e[i].u, e[i].v))
            cnt++, ans += e[i].w;
        i++;
    }
    cout << ans << '\n';
    return 0;
}
