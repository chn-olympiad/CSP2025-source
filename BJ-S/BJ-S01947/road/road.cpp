#include<bits/stdc++.h>
using namespace std;
#define N 10004
int n, m, k, f[N + 10], now[(N << 1) + 10];
int mem[1025][N + 10], c[15];
long long ans;
struct node { int u, v, w; } mp[N * 10 + 1000000];
inline bool cmp(node x, node y) { return x.w > y.w; }
inline int find(int x) { return f[x] ^ x ? f[x] = find(f[x]) : x; }
inline bool cmp2(int x, int y) { return mp[x].w > mp[y].w; }
inline void check(int x) {
    if(mem[x][0]) return;
    //cout << x << endl;
    int cnt = 0;
    for(int i = k - 1; ~i; --i) {
        if(x & (1 << i)) {
            check(x - (1 << i));
            for(int j = mem[x - (1 << i)][0]; j; --j) 
                now[++cnt] = mem[x - (1 << i)][j];
            for(int j = n; j; --j) 
                now[++cnt] = m + i * n + j;
            break;
        }
    }
    long long ret = 0;
    for(int i = k - 1; ~i; --i) 
        if(x & (1 << i)) ret += c[i];
    sort(now + 1, now + cnt + 1, cmp2);
    for(int i = n + k; i; --i) f[i] = i;
    for(int i = cnt; i; --i) {
        int uu = find(mp[now[i]].u), vv = find(mp[now[i]].v);
        if(uu ^ vv) {
            ret += mp[now[i]].w, f[uu] = vv, mem[x][++mem[x][0]] = now[i];
            //cout << mp[now[i]].u << "  " << mp[now[i]].v << "  " << ret << endl;
        }
    }
    //cout << ret << endl;
    ans = ans < ret ? ans : ret;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //cout << sizeof(mem) + sizeof(mp);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = m; i; --i) cin >> mp[i].u >> mp[i].v >> mp[i].w;
    sort(mp + 1, mp + m + 1, cmp);
    for(int i = n; i; --i) f[i] = i;
    for(int i = m; i; --i) {
        int uu = find(mp[i].u), vv = find(mp[i].v);
        if(uu ^ vv) 
            ans += mp[i].w, f[uu] = vv, mem[0][++mem[0][0]] = i;
    }
    //cout << 1111111 << endl;
    for(int i = 0; i < k; ++i) {
        cin >> c[i];
        for(int j = 1; j <= n; ++j) {
            int aa;
            cin >> aa;
            mp[m + i * n + j] = {j, n + i + 1, aa};
            //cout << j << "  " << n + i + 1 << "  " << aa << endl;
        }
    }
    //cout << 111111 << endl;
    for(int i = (1 << k) - 1; i; --i) check(i);
    printf("%lld", ans);
    return 0;
}