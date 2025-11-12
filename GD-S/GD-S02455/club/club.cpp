#include <bits/stdc++.h>
#define rep(_x,_y,_z) for(int _x=_y; _x <= _z; _x++)
#define rrep(_x,_y,_z) for(int _x=_y; _x >= _z; _x--)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int a[100005][4];

void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    int ans = 0, flag1 = 0;
    rep(k, 1, 3) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int cnt = n / 2, tot = 0;
        rep(i, 1, n) {
            pq.push(a[i][k] - max(a[i][k%3+1], a[i][(k+1)%3+1]));
            tot += a[i][k];
        }
        int flag2 = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (p < 0) flag2 = 1;
            tot -= p;
            cnt--;
            if (cnt == 0) break;
        }
        if (flag2) flag1 ++;
        ans = max(ans, tot);
    }
    if (flag1 == 3) {
        ans = 0;
        rep(i, 1, n) {
            ans += max(a[i][1], max(a[i][2], a[i][3]));
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}