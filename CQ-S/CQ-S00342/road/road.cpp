#include<bits/stdc++.h>
typedef long long ll;
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
int n, m, k, fa[N], siz[N], c[N], a[15][10005], cnt;
ll ans;
inline int FindSet(int x) {return fa[x] == x ? x : fa[x] = FindSet(fa[x]);}
struct edge {
    int u, v, w;
    bool operator <(const edge &t) const {return w < t.w;}
} arr[N], brr[15][10005];
int cur[15], vis[15];
vector<int> pos;
inline void chk(int k_, ll sum) {
    for(int i = 1; i <= n + k; ++i) fa[i] = i, siz[i] = 1;
    ll res = 0, tot = 0;
    while(true) {
        int w = 0x3f3f3f3f, p = 0;
        for(auto i : pos) if(cur[i] <= n && brr[i][cur[i]].w < w) w = brr[i][cur[i]].w, p = i;
        int x = FindSet(brr[p][cur[p]].u), y = FindSet(brr[p][cur[p]].v);
        cur[p]++;
        if(x == y) continue;
        if(siz[x] > siz[y]) swap(x, y);
        res += w, fa[x] = y, siz[y] += siz[x], tot++;
        if(tot == n + k_ - 1 || res + sum >= ans) break;
    }
    ans = min(ans, res + sum);
    return;
}
inline void SOLVE() {
    cin>>n>>m>>k;
    for(int i = 1; i <= m; ++i)
        cin>>arr[i].u>>arr[i].v>>arr[i].w;
    for(int i = 1; i <= k; ++i) {
        cin>>c[i];
        for(int j = 1; j <= n; ++j) cin>>brr[i][j].w, brr[i][j].u = n + i, brr[i][j].v = j;
        sort(brr[i] + 1, brr[i] + n + 1);
    }
    sort(arr + 1, arr + m + 1);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= m; ++i) {
        int x = FindSet(arr[i].u), y = FindSet(arr[i].v);
        if(x == y) continue;
        ans += arr[i].w, fa[x] = y, brr[0][++cnt] = arr[i];
    }
    brr[0][++cnt] = {0, 0, 0x3f3f3f3f};
    for(int i = (1 << k) - 1; i > 0; --i) {
        ll sum = 0, ks = 0;
        pos.clear(), cur[0] = 1, pos.push_back(0);
        for(int j = 0; j < k; ++j) if(i >> j & 1) {
            vis[j + 1] = true, cur[j + 1] = 1, sum += c[j + 1], ks++, pos.push_back(j + 1);
        } else vis[j + 1] = false;
        chk(ks, sum);
    }
    cout<<ans<<'\n';
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--) SOLVE();
    cerr<<clock() * 1.0 / CLOCKS_PER_SEC<<'\n';
    return 0;
}
//g++ -o -std=c++14 -O2 -DddxrS; ./