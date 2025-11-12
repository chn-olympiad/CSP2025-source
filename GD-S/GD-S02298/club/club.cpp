#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n;
int a[N][5];

struct cmp {
    bool operator()(pair<int, int> x, pair<int, int> y) {
        return a[x.first][x.second] < a[y.first][y.second];
    }
};

int tot[5], tag[N];

void clear() {
    memset(tot, 0, sizeof(tot));
    memset(tag, 0, sizeof(tag));
}

void solve() {
    cin >> n;
    using T = pair<int, int>;
    priority_queue<T, vector<T>, cmp> pq;
    priority_queue<tuple<int, int, int>> pq1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            pq.emplace(i, j);
        }
    }

    long long ans = 0;
    while(pq.size()) {
        auto [x, y] = pq.top(); pq.pop();
        if(tag[x]) {
            pq1.emplace(a[x][y] - a[x][tag[x]], tag[x], x);
            continue;
        }
        ans += a[x][y];

        tot[y]++, tag[x] = y;
        
    }

    int flag = 0;
    for(int i = 1; i <= 3; i++) {
        if(tot[i] > n / 2) flag = i;
    }

    if(!flag) {
        cout << ans << '\n';
        clear();
        return;
    }

    while(pq1.size() && tot[flag] >  n / 2) {
        auto [x, y, z] = pq1.top(); pq1.pop();
        if(y != flag || tag[z] != flag) continue;

        ans += x, tag[z] = 8;
        tot[flag]--;
    }

    cout << ans << '\n';

    clear();
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin >> t;

    while(t--) {
        solve();
    }
}