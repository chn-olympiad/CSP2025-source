#include <bits/stdc++.h>
using namespace std;
#define inlfc __attribute__((always_inline))
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

struct Triple {
    int a, b, c;
};

struct cmp {
    inlfc bool operator ()(const Triple& a, const Triple& b) const {
        return a.a < b.a;
    }
};

int n;
int a[MAXN][5], cnt[5] = {};
ll ans = 0, s;

void dfs(int x) {
    if (x == n + 1) {
        ans = max(ans, s);
    }
    for (int i = 1; i <= 3; i ++) {
        if (cnt[i] < n >> 1) {
            cnt[i] ++;
            s += a[x][i];
            dfs(x + 1);
            cnt[i] --;
            s -= a[x][i];
        }
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        cin >> n;
        bool vis[MAXN] = {};
        ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) a[i][j] = 0;
        }
        for (int j = 0; j <= 3; j ++) cnt[j] = 0;
        priority_queue<Triple, vector<Triple>, cmp> pq;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cin >> a[i][j];
                pq.push({a[i][j], i, j});
            }
        }
        if (n <= 20) {
            s = 0;
            dfs(1);
        } else {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= 3; j ++) {
                    pq.push({a[i][j], i, j});
                }
                while (cnt[0] < n) {
                    auto [x, i, d] = pq.top();
                    pq.pop();
                    if (!vis[i] && cnt[d] < n >> 1) {
                        vis[i] = 1;
                        ans += x;
                        cnt[0] ++;
                        cnt[d] ++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
