#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = (1 << 21);
int n, k;
int a[N], lst[M], dp[N], lef[N];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)cin >> a[i];
    int xornum = 0;
    for (int i = 0; i < M; i++)lst[i] = -1;
    lst[0] = 0;
    for (int i = 1; i <= n; i++) {
        xornum ^= a[i];
        lef[i] = lst[xornum ^ k];
        lst[xornum] = i;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if(lef[i] != -1)dp[i] = max(dp[i], dp[lef[i]] + 1);
    }
    cout << dp[n];
    return 0;
}