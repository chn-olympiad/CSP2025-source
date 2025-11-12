#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
int fa[100005];int c[105]; int a[15][100005];
struct edge {
    int u,v,w,f,id;
}e[N];
int m; int vis[105];
int findfa(int x) {
    if(fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
bool cmp(edge a,edge b) {
    return a.w < b.w;
}
bool cmp2(edge a,edge b) {
    if(a.f == 1 && b.f == 0) { return a.w + c[a.id] < b.w; }
    if(a.f == 1 && b.f == 1) { return a.w + c[a.id] < b.w + c[b.id];}
    if(a.f == 0 && b.f == 1) { return a.w < b.w + c[b.id]; }
    return a.w < b.w;
}
int kruskal() {
    sort(e + 1,e + m + 1,cmp);
    long long ans = 0;
    for(int i = 1;i <= m;i++) {
        int fu = findfa(e[i].u);
        int fv = findfa(e[i].v);
        if(fu == fv) continue;
        fa[fu] = fv; ans += e[i].w;
    }
    return ans;
}
int kruskal2() {
    sort(e + 1,e + m + 1,cmp2);
    long long ans = 0;
    for(int i = 1;i <= m;i++) {
        int fu = findfa(e[i].u);
        int fv = findfa(e[i].v);
        if(fu == fv) continue;
        fa[fu] = fv;
        if(e[i].f == 1) { ans += e[i].w + c[e[i].id]; if(vis[e[i].id] == 1) {ans -= c[e[i].id];} vis[e[i].id] = 1;}
        else {ans += e[i].w;}
    }
    return ans;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,k; cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m;i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].f = 0;
    }
    if(k == 0) { cout << kruskal();}
    else {
        bool flag = 0;
        for(int i = 1;i <= k;i++) {
            cin >> c[i];
            if(c[i] != 0) flag = 1;
            for(int j = 1;j <= n;j++) {
                cin >> a[i][j];
            }

        }
        for(int j = 1;j <= n;j++) {
            for(int y = 1;y <= n;y++) {
                if(j == y) continue;
                for(int i = 1;i <= k;i++) {
                    e[++m].u = j;
                    e[m].v = y;
                    e[m].w = a[i][j] + a[i][y];
                    e[m].f = 1,e[m].id = i;
                }

            }
        }
        if(!flag) cout << kruskal() << endl;
        if(flag) cout << kruskal2() << endl;
    }
    return 0;
}
