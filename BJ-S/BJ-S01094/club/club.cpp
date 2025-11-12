#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ft first
#define sd second
using namespace std;
struct S {
    int x, y, z;
};
int T, n;
int a[100005][4];
bool b[100005];
int dp[205][205][205], tmp[205][205][205];
void brute() {
    memset(dp, 0, sizeof(dp));
    memset(tmp, 0, sizeof(tmp));
    vector<S> sta;
    for(int i = 0; i <= n / 2; i++) {
        for(int j = 0; j <= n / 2; j++) {
            for(int k = 0; k <= n / 2; k++) {
                if(i + j + k <= n) {
                    sta.push_back({i, j, k});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(S s : sta) {
            int& now = dp[s.x][s.y][s.z];
            now = tmp[s.x][s.y][s.z];
            if(s.x) {
                now = max(now, tmp[s.x - 1][s.y][s.z] + a[i][1]);
            }
            if(s.y) {
                now = max(now, tmp[s.x][s.y - 1][s.z] + a[i][2]);
            }
            if(s.z) {
                now = max(now, tmp[s.x][s.y][s.z - 1] + a[i][3]);
            }
        }
        for(S s : sta) {
            int& now = dp[s.x][s.y][s.z];
            tmp[s.x][s.y][s.z] = now;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n / 2; i++) {
        for(int j = 0; j <= n / 2; j++) {
            for(int k = 0; k <= n / 2; k++) {
                if(i + j + k == n) {
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }
    cout << ans << endl;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> v[4];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                if(a[i][j] == max({a[i][1], a[i][2], a[i][3]})) {
                    int x = INT_MIN;
                    for(int k = 1; k <= 3; k++) {
                        if(k != j) {
                            x = max(x, a[i][k] - a[i][j]);
                        }
                    }
                    v[j].push_back(x);
                    ans += a[i][j];
                    break;
                }
            }
        }
        for(int i = 1; i <= 3; i++) {
            sort(v[i].begin(), v[i].end());
        }
        for(int i = 1; i <= 3; i++) {
            while(v[i].size() > n / 2) {
                ans += v[i].back();
                v[i].pop_back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}
