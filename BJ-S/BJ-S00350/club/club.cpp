#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MaxN = 205;
int n, a[N][3];
int dp[MaxN][MaxN][MaxN];
void solve(){
    cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, s = 0;
    bool ok = 1;
    for (int i = 1;i <= n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        ok &= (a[i][1] == 0) && (a[i][2] == 0);
        int mx = max(max(a[i][0], a[i][1]), a[i][2]);
        s += mx;
        if (mx == a[i][0]) cnt1++;
        if (mx == a[i][1]) cnt2++;
        if (mx == a[i][2]) cnt3++;
    }
    if (ok){
        vector<int> v;
        for (int i = 1;i <= n;i++)
            v.push_back(a[i][0]);
        sort(v.begin(), v.end(), greater<int>());
        s = 0;
        for (int i = 0;i < n / 2;i++)
            s += v[i];
        cout << s << endl;
        return;
    }
    int hf = n / 2;
    if (n <= 200){
        int ans = 0;
        for (int i = 0;i <= n;i++){
            for (int j = 0;j <= n;j++){
                if (i + j > n) break;
                for (int k = 0;k <= n;k++){
                    s = i + j + k;
                    if (s > n) break;
                    if (s == 0){
                        dp[i][j][k] = 0;
                        continue;
                    }
                    dp[i][j][k] = 0;
                    if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[s][0]);
                    if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[s][1]);
                    if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[s][2]);
                    if (i <= hf && j <= hf && k <= hf){
                        ans = max(ans, dp[i][j][k]);
                        // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
                    }
                }
            }
        }
        cout << ans << endl;
        return;
    }
    cout << s << endl;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
/*
70 pts
*/
