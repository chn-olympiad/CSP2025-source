#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, inf = 2e10;
int T, n, cnt[3], Ans;
vector <int> v[3], wt;
typedef pair <int, int> Pii;
struct Node {int a[3];} s[N];
inline void clear() {
    for(int i = 0; i < 3; ++ i) cnt[i] = 0, v[i].clear();
    Ans = 0, wt.clear();
}
inline void solve() {
    cin >> n; clear(); int lim = n / 2;
    for(int i = 1; i <= n; ++ i) {
        int mx = -1, mi = 0;
        for(int j = 0; j < 3; ++ j) {
            cin >> s[i].a[j];
            if(mx < s[i].a[j]) mx = s[i].a[j], mi = j;
        }
        Ans += mx, ++ cnt[mi], v[mi].emplace_back(i);
    }
    if(cnt[0] <= lim && cnt[1] <= lim && cnt[2] <= lim) {cout << Ans << '\n'; return ;}
    int nd = -1; for(int j = 0; j < 3; ++ j) if(cnt[j] > lim) nd = j;
    for(int o : v[nd]) {
        int mn = inf;
        for(int j = 0; j < 3; ++ j) {
            if(j == nd) continue;
            mn = min(s[o].a[nd] - s[o].a[j], mn);
        }
        wt.emplace_back(mn);
    }
    sort(wt.begin(), wt.end());
    for(int j = 0; j < cnt[nd] - lim; ++ j) Ans -= wt[j];
    cout << Ans << '\n';
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); cin >> T;
    while(T --) solve();
    return 0;
}
// Ren5Jie4Di4Ling5%