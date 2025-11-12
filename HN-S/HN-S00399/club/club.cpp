#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int kmax = 1e5 + 3;

long long res;
int t, a[kmax][3];
priority_queue<int> q[3];
int n;

void Solve() {
    cin >> n;
    for(int i = 0; i < 3; i++) {
        for(; !q[i].empty(); q[i].pop()) {
        }
    }
    res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        int mx = max({a[i][0], a[i][1], a[i][2]});
        res += mx;
        if(mx == a[i][0]) {
            q[0].push(max(a[i][1], a[i][2]) - a[i][0]);
        } else if(mx == a[i][1]) {
            q[1].push(max(a[i][0], a[i][2]) - a[i][1]);
        } else {
            q[2].push(max(a[i][0], a[i][1]) - a[i][2]);
        }
    }
    for(int i = 0; i < 3; i++) {
        for(; q[i].size() > n / 2; q[i].pop()) {
            res += q[i].top();
        }
    }
    cout << res << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) Solve();
    return 0;
}