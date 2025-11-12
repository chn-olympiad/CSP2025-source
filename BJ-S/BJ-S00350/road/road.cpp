#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 11005;
const int MaxM = 1.1e6 + 5;
int n, m, k;
int c[15], a[15][N];
struct qwq{
    int x, y, z;
    bool operator < (const qwq &b) const {
        return z < b.z;
    }
}e[MaxM], e1[MaxM];
int m1, f[N];
int find(int x){
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int work(int t){
    m1 = m;
    int s = 0, n1 = n;
    for (int i = 1;i <= m;i++)
        e1[i] = e[i];
    for (int i = 0;i < k;i++){
        if ((t & (1 << i)) == 0) continue;
        s += c[i]; n1++;
        for (int j = 1;j <= n;j++){
            e1[++m1] = {n1, j, a[i][j]};
        }
    }
    sort(e1 + 1, e1 + m1 + 1);
    for (int i = 1;i <= n1;i++) f[i] = i;
    for (int i = 1;i <= m1;i++){
        int fx = find(e1[i].x), fy = find(e1[i].y);
        if (fx == fy) continue;
        f[fx] = fy;
        s += e1[i].z;
    }
    return s;
}
void solve(){
    for (int i = 1;i <= m;i++){
        cin >> e[i].x >> e[i].y >> e[i].z;
    }
    for (int i = 0;i < k;i++){
        cin >> c[i];
        for (int j = 1;j <= n;j++) cin >> a[i][j];
    }
    int ans = 1e18;
    for (int i = 0;i < (1 << k);i++){
        int ret = work(i);
        ans = min(ans, ret);
    }
    cout << ans;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    if (n <= 1e3 && m <= 1e5 && k <= 5) solve();
    else cout << 0;
}
/*
52 pts
*/
