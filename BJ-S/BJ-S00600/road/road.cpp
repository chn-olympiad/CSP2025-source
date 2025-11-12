#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e6 + 7;
int n, m, k, fa[N];
long long ans = 0;
bool box[N];
struct node {
    int x, y;
    long long w;
}a[N];
bool cmp(node a, node b) {
    return a.w < b.w;
}
int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void kruskal() {
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        auto [u, v, w] = a[i];
        int ru = find(u), rv = find(v);
        if(ru != rv) {
            ans += w;
            cnt++;
            fa[ru] = find(rv);
        }
        if(cnt == n - 1) break;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
    }
    sort(a + 1, a + m + 1, cmp);
    kruskal();
    while(k--) {
        for(int i = 0, x; i <= n; i++) cin >> x;
    }
    cout << ans << endl;
    return 0;
}
