#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 5010;
int a[N];
int dp[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k =1; k <= n; k++) {
                if (i == j || i == k || j == k) continue;
                int mx = INT_MIN, sum = 0;
                sum = i+j+k;
                if (sum > 2 * mx) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}