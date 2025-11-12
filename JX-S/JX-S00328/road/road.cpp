#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
int n, m, k, ans;
int cnt;
int tag[N], o[N];
int f[N];
struct K {
    int u, v, w, sign;
}way[M << 1];
int sum = 0;
void si(int x, int y,int  z) {
    sum ++ ;
    way[sum].u = x;
    way[sum].v = y;
    way[sum].w = z;
    return ;
}int cmp(K x, K y) {
    if(x.w != y.w) return x.w < y.w;
    else return x.sign < y.sign;
}int find(int x) {
    if(f[x] == x) {
        return f[x];
    }return f[x] = find(f[x]);
}void dfs() {
    int p = 0;
    while(ans != n && sum--) {
        p++;
        if(o[way[p].u] && o[way[p].v]) {
            continue;
        }int ss=find(way[p].v),rr=find(way[p].u);
        if(ss == rr) {
            continue;
        }f[ss] = rr;
        if(!o[way[p].u] && way[p].u <= n && 1 <= way[p].u) ans++;
        if(!o[way[p].v] && way[p].v <= n && 1 <= way[p].v) ans++;
        cnt += way[p].w;
        o[way[p].u] = 1;
        o[way[p].v] = 1;

    }return;

}signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        si(U,V,W);
        si(V,U,W);
    }for(int i = 1; i <= k; i++) {
        cin >> tag[i+n];
        for(int j = 1; j <= n; j++) {
            int W;
            cin >> W;
            if(i == j) continue;
            si(i+n, j, W + tag[i]);
            if(tag[i+n]) way[sum].sign = i+n;
            si(j, i+n, W + tag[i]);
            if(tag[i+n]) way[sum].sign = i+n;
        }
    }sort(way+1, way+1+sum, cmp);
    dfs();
    cout << cnt;
    return 0;
}
