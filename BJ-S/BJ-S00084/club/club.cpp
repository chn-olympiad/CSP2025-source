#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int N = 1e5 + 10;

struct myPair {
    int id, v;
    inline bool operator<(const myPair &b) const {
        return v < b.v;
    }
};

int T, n, ans;
int a[N][3], vis[N], cnt[3];
priority_queue<myPair> b[3];

void clear() {
    for(int i = 0; i < 3; i++) {
        while(!b[i].empty()) b[i].pop();
        cnt[i] = 0;
    }
    ans = 0;
    for(int i = 1; i <= n; i++) vis[i] = 0;
}

signed main() {

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> n;
        clear();
        for(int i = 1; i <= n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
                ++cnt[0];
                b[0].push({i, a[i][1] - a[i][0]});
                b[0].push({i, a[i][2] - a[i][0]});
            } else if(a[i][1] > a[i][2]) {
                ++cnt[1];
                b[1].push({i, a[i][0] - a[i][1]});
                b[1].push({i, a[i][2] - a[i][1]});
            } else {
                ++cnt[2];
                b[2].push({i, a[i][0] - a[i][2]});
                b[2].push({i, a[i][1] - a[i][2]});
            }
            ans += max(a[i][0], max(a[i][1], a[i][2]));
        }
        int p = -1;
        if(cnt[0] > n / 2) p = 0;
        else if(cnt[1] > n / 2) p = 1;
        else if(cnt[2] > n / 2) p = 2;
        if(p == -1) {
            cout << ans << '\n';
        } else {
            while(cnt[p] > n / 2) {
                while(vis[b[p].top().id]) b[p].pop();
                ans += b[p].top().v;
                vis[b[p].top().id] = 1;
                b[p].pop();
                cnt[p]--;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}