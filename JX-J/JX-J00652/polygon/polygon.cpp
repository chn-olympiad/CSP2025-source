#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 5, MOD = 998244353;
int n;
int arr[N];
//int dp[N], sum[N];

//vector<int> path;

int dfs(int sum, int maxn, int m, int i) {
    if (i > n) {
        if (sum > 2 * maxn && m >= 3) return 1;
        return 0;
    }
    int p1 = dfs(sum + arr[i], (maxn > arr[i] ? maxn : arr[i]), m + 1, i + 1);
    int p2 = dfs(sum, maxn, m, i + 1);
    return p1 + p2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "W", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        //sum[i] += sum[i - 1] + arr[i];
    }

    cout << dfs(0, -1, 0, 1);
    return 0;
}
