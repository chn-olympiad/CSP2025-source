#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e5+5;
int n, k, arr[N];
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++){
        ll v = 0;
        dp[i] = dp[i-1];
        for (int j = i; j >= 1; j--){
            v ^= arr[j];
            if (v == k) {
                dp[i] = max(dp[i], dp[j-1] + 1);
                break;
            }
        }
    }
    //for (int i = 1; i <= n; i++){
    //    cout << dp[i] << ' ';
    //}
    cout << dp[n];
    return 0;
}
