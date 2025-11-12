#include <bits/stdc++.h>
using namespace std;
int a[500005];
int dp[1000005][2];
struct Node{
    int l, r;
};
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<Node>b;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = i; j <= n; j++) {
            x ^= a[j];
            if (x == k) {
                b.push_back(Node{i, j});
            }
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < b.size(); i++) {
        int n = 0, y = 0;
        for (int j = 0; j < i; j++) {
            n = max ({n, dp[j][0], dp[j][1]});
            if (b[j].r < b[i].l) {
                y = max (y, max (dp[j][1], dp[j][0]) + 1);
            }
        }
        dp[i][0] = n;
        dp[i][1] = y;
    }
    cout << max (dp[b.size() - 1][0], dp[b.size() - 1][1]);
    return 0;
}
