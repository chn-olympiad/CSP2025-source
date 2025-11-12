#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    if (n >= 200){
        priority_queue<pair<int, pair<int, int> > >pq;
        for (int i = 1; i <= n; i++){
            pq.push({a[i][1], {i, 1}});
            pq.push({a[i][2], {i, 2}});
            pq.push({a[i][3], {i, 3}});
        }
        // cerr << pq.size() << endl;
        map<int, int>vis;
        map<int, int>cnt[4];
        ll ans = 0;
        while (!pq.empty()){
            auto cur = pq.top();
            auto w = cur.first, now = cur.second.first, ch = cur.second.second;
            pq.pop();
            if(vis[now]==0){
                if (cnt[ch][ch] >= n / 2){
                    continue;
                }
                vis[now] = 1;
                cnt[ch][now] = 1;
                ans += w;
            }
        }
        cout << ans << endl;
        return;
    }
    vector<vector<vector<vector<vector<ll> > > > > dp(n + 1, vector<vector<vector<vector<ll> > > >(n / 2 + 2, vector<vector<vector<ll> > >(n / 2 + 2, vector<vector<ll> >(n / 2 + 2, vector<ll>(2, 0)))));
    // dp[1][1][0][0][1] = a[1][1];
    // dp[1][0][1][0][1] = a[1][2];
    // dp[1][0][0][1][1] = a[1][3];
    for (int i = 1; i <= n; i++){
        for (int st1 = 0; st1 <= n / 2; st1++){
            for (int st2 = 0; st2 <= n / 2; st2++){
                for (int st3 = 0; st3 <= n / 2; st3++){
                    if(st1 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1 - 1][st2][st3][1] + a[i][1]);
                    if(st2 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1][st2 - 1][st3][1] + a[i][2]);
                    if(st3 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1][st2][st3 - 1][1] + a[i][3]);

                    if(st1 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1 - 1][st2][st3][0] + a[i][1]);
                    if(st2 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1][st2 - 1][st3][0] + a[i][2]);
                    if(st3 > 0) dp[i][st1][st2][st3][1] = max(dp[i][st1][st2][st3][1], dp[i - 1][st1][st2][st3 - 1][0] + a[i][3]);

                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][1]);
                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][1]);
                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][1]);

                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][0]);
                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][0]);
                    dp[i][st1][st2][st3][0] = max(dp[i][st1][st2][st3][0], dp[i - 1][st1][st2][st3][0]);
                }
            }
        }
    }
    cout << max(dp[n][n/2][n/2][n/2][0], dp[n][n/2][n/2][n/2][1]) << endl;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}
