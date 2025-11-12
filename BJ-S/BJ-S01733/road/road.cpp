#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int f, t, v;
} e[1000005];
int a[15][100005];
int f[1000005];
int vis[1000005];
int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
}
int n, m, k;
bool cmp(node x, node y) {
    return x.v < y.v;
}
int viss[15][100005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].f >> e[i].t >> e[i].v;
    }
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= k; i ++) {
        for (int j = 0; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    map <int, int> mp;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = e[i].f, y = e[i].t, v = e[i].v;
        int fx = find(x), fy = find(y);
        // cout << fx << " " << fy << " " << v << "\n";
        if (fx == fy) continue;
        int minn = 1e18;
        int xx, yy, kk = 0;
        for (int j = 1; j <= k; j ++) {
            int tmp = 0;
            if (!vis[j]) tmp = a[j][0];
            int minnn = 1e18;
            for (int l = 1; l <= n; l ++) {
                if (find(l) == fx) {
                    if (a[j][l] < minnn) {
                        minnn = a[j][l];
                        xx = l;
                    } 
                } 
            }
            tmp += minnn;
            minnn = 1e18;
            // cout << tmp << "\n";
            for (int l = 1; l <= n; l ++) {
                if (find(l) == fy) {
                    if (a[j][l] < minnn) {
                        minnn = a[j][l];
                        yy = l;
                        // cout << l << " " << a[j][l] << "\n";
                    } 
                } 
            }
            tmp += minnn;
            // cout << tmp << "\n";
            // cout << xx << " " << yy << " " << tmp << " !\n";
            if (tmp < minn) {
                minn = tmp;
                kk = j;
            }
        }
        // cout << "!!!\n";
        // cout << xx << " " << yy << " " << kk << " " << minn << "\n";
        if (minn <= v) {
            vis[kk] = 1;
            viss[kk][xx] = viss[kk][yy] = 1;
            a[kk][xx] = 0;
            a[kk][yy] = 0;
        }
        // else {
            merge(x, y);
        // }
        cnt ++;
        ans += min(minn, v);
        // cout << ans << "\n";
        if (cnt > n) break;

    }
    cout << ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/