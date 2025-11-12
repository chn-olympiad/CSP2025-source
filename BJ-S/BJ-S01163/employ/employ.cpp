#include <iostream>
using namespace std;

typedef long long ll;
const int NR = 505;
const ll mod = 998244353;

int n, m;
int s[NR], c[NR];

namespace slv10 {
    bool vis[NR];
    int ans = 0;

    void dfs(int x, int cnt) {
        if (x == n + 1) {
            if (cnt >= m)
                ans++;
            return;
        }

        if (cnt + n - x + 1 < m) continue;

        bool stt;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                stt = (s[x] == 1) && (x - 1 - cnt < c[i]);
                dfs(x + 1, cnt + stt);
                vis[i] = false;
            }
        }
    }

    void solve10() {
        dfs(1, 0);
        printf("%d\n", ans);
    }
}

namespace slv_s {
    void solve_s() {
        ll ans = 1;
        for (int i = 1; i <= n; i++)
            ans = ans * i % mod;
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string inps;
    bool flg_s = true;

    cin >> n >> m;

    cin >> inps;
    for (int i = 1; i <= n; i++) {
        s[i] = inps[i - 1] - '0';
        flg_s &= (s[i] == 1);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];

    if (n <= 18)
        slv10::solve10();
    else
        slv_s:;solve_s();
    return 0;
}