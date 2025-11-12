#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// char _m_s;
const int MAXN = 1e5 + 5;

int n, ans;
pair<int, int> a[MAXN][3];
vector<int> club[3], tmp;

void chk(int c) {
    int need = (int)club[c].size() - n / 2;
    if (need > 0) {
        tmp.clear();
        for (int x : club[c]) {
            tmp.push_back(a[x][0].first - a[x][1].first);
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < need; ++i) {
            ans -= tmp[i];
        }
    }
}

void solve() {
    club[0].clear(); club[1].clear(); club[2].clear();
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i][0] = { x, 0 };
        a[i][1] = { y, 1 };
        a[i][2] = { z, 2 };
        sort(a[i], a[i] + 3, greater<pair<int, int> >());
        ans += a[i][0].first;
        club[a[i][0].second].push_back(i);
    }
    chk(0); chk(1); chk(2);
    printf("%d\n", ans);
}
// char _m_e;

int main() {
    // fprintf(stderr, "memory:%.2lfMB\n", (&_m_e - &_m_s) / 1048576.0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}