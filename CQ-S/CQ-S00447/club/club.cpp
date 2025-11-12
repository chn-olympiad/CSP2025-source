#include <bits/stdc++.h>

#define fin(s) freopen(s".in", "r", stdin)
#define fout(s) freopen(s".out", "w", stdout)

using i64 = long long;
using namespace std;

template<typename T>
void read(T &x) {
    char ch = getchar();
    x = 0;
    T f = 1;

    while (!isdigit(ch)) {
        f -= (ch == '-') << 1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch & 15);
        ch = getchar();
    }

    x *= f;
}
template<typename T, typename ...L>
void read(T &x, L &...y) {
    read(x);
    read(y...);
}

constexpr int N = 1E5 + 5;

int n;
i64 ans;
int a[N][3];
vector<int> w[3];

void solve() {
    cin >> n;

    for (int i = 0; i < 3; ++i) {
        w[i].clear();
    }
    ans = 0;

    for (int i = 1; i <= n; ++i) {
        vector<pair<int, int>> v;
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            v.emplace_back(a[i][j], j);
        }
        sort(v.begin(), v.end());
        ans += v[2].first;
        w[v[2].second].push_back(v[1].first - v[2].first);
    }

    for (int i = 0; i < 3; ++i) {
        sort(w[i].begin(), w[i].end());
        while (w[i].size() > n / 2) {
            ans += w[i].back();
            w[i].pop_back();
        }
    }

    cout << ans << "\n";
}

int main() {
    fin("club");
    fout("club");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}