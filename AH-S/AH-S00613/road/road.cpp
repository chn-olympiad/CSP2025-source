#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 2000005
using namespace std;
typedef long long ll;
int n, m, k, ct;
ll ans;
bool vis[15], vis2[15];
int c[15], fa[12005];
struct edge{
    int u, v, w;
}a[MAXN];
void init() {
    for(int i=1; i<=n+k; i++) {
        fa[i] = i;
    }
    return ;
}
int find(int x) {
    if(fa[x]==x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) {
        return ;
    }
    fa[y] = x;
    return ;
}
bool same(int x, int y) {
    return find(x)==find(y);
}
bool cmp(edge x, edge y) {
    return x.w<y.w;
}
ll Kruscal(int ct) {
    ll sum = 0;
    init();
    for(int i=1; i<=k; i++) {
        if(vis[i]) {
            sum += c[i];
        }
    }
    int cnt = 0;
    for(int i=1; i<=m; i++) {
        if((a[i].u>n&&!vis[a[i].u-n])||(a[i].v>n&&!vis[a[i].v-n])) {
            continue;
        }
        if(!same(a[i].u, a[i].v)) {
            unite(a[i].u, a[i].v);
            sum += a[i].w;
            cnt ++;
        }
        if(cnt==n-1+ct) {
            break;
        }
    }
    return sum;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a+1, a+1+m, cmp);
    ans = Kruscal(0);
    for(int i=1; i<=k; i++) {
        cin >> c[i];
        for(int j=1; j<=n; j++) {
            cin >> a[++m].w;
            a[m].u = n+i;
            a[m].v = j;
        }
    }
    sort(a+1, a+1+m, cmp);
    for(int i=1; i<=k; i++) {
        vis[i] = true;
        ll now = Kruscal(1);
        vis[i] = false;
        if(ans>now) {
            vis2[i] = true;
            ct ++;
        }
    }
    for(int i=1; i<=k; i++) {
        vis[i] = vis2[i];
    }
    ans = Kruscal(ct);
    cout << ans;
    return 0;
}
