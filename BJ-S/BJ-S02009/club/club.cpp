#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#define maxn 100005
#define pli std::pair<long long, int>

long long a[maxn], b[maxn], c[maxn];
int n;
bool vis[maxn];
void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i] >> c[i], vis[i] = 0;
    long long ans = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            if (a[i] > c[i]) ans += a[i], ++cnt1;
            else ans += c[i], ++cnt3;
        }
        else if (b[i] > c[i]) ans += b[i], ++cnt2;
        else ans += c[i], ++cnt3;
    }
    if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
        std::cout << ans << "\n";
        return;
    }
    int cnt; long long *d, *e, *f;
    if (cnt1 > n / 2) cnt = cnt1, d = a, e = b, f = c;
    else if (cnt2 > n / 2) cnt = cnt2, d = b, e = a, f = c;
    else cnt = cnt3, d = c, e = a, f = b;
    std::priority_queue<pli, std::vector<pli>, std::greater<pli>> q;
    for (int i = 1; i <= n; i++) if (d[i] > e[i] && d[i] > f[i]) q.push({d[i] - e[i], i}), q.push({d[i] - f[i], i});
    cnt -= n / 2;
    while (cnt > 0) {
        long long dt = q.top().first; int num = q.top().second; q.pop();
        if (vis[num]) continue;
        --cnt;
        vis[num] = 1;
        ans -= dt;
    }
    std::cout << ans << "\n";
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
    int t; std::cin >> t;
    while (t--) solve();
    return 0;
}
