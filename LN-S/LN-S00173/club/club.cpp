#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1,vector<int>(4)),vis(4);

    i64 ans = 0;

    for (int i = 1;i <= n;i++){
        int ma = 0;
        for (int j = 1;j <= 3;j++)
            cin >> a[i][j],ma = max(ma,a[i][j]);

        for (int j = 1;j <= 3;j++)
            if (a[i][j] == ma){
                vis[j].push_back(i);
                break;
            }

        ans += ma;
    }

    for (int i = 1;i <= 3;i++)
        if ((int)vis[i].size() > n / 2){
            for (auto &j:vis[i]){
                sort(a[j].begin() + 1,a[j].end());
                j = a[j][3] - a[j][2];
            }

            sort(vis[i].begin(),vis[i].end(),greater<int>{});

            int len = vis[i].size();

            for (;len > n / 2;len--)
                ans -= vis[i].back(),vis[i].pop_back();
        }

    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;

    for (;T--;solve());
}
