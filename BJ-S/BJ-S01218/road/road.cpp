#include<bits/stdc++.h>
using namespace std;
long long n, m, k, ans, fa[10005], b[10005], c[10005];
struct Edge{
    int u, v, value;
}a[10000005];
bool cmp(Edge x, Edge y) {
    return x.value < y.value;
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}
void Kruskal() {
    int cnt = n;
    for(int i = 1; i <= m; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        if(find(a[i].u) != find(a[i].v)) {
            merge(a[i].u, a[i].v);
            cnt--;
            ans += a[i].value;
            if(cnt == 1) {
                break;
            }
        }
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    if(k == 0) {
        for(int i = 1; i <= n; i++){
            int u, v, value;
            cin >> u >> v >> value;
            Edge x = {u, v, value};
            a[i] = x;
        }
        sort(a + 1, a + 1 + m, cmp);
        Kruskal();
        cout << ans << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int u, v, value;
        cin >> u >> v >> value;
        Edge x = {u, v, value};
        a[i] = x;
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> b[j];
            for(int B = 1; B <= j; B++) {
                a[++m] = {j, B, b[B] + b[j]};
            }
        }
    }
    sort(a + 1, a + 1 + m, cmp);
    Kruskal();
    cout << ans << endl;
    return 0;
}
