#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6 + 5;
int n, k, a[MAXN], dp[MAXN], mx[MAXN];

signed main(){
    freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k; for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < (1 << 20); ++i) mx[i] = -1;
    for(int i = 1; i <= n; ++i){
        a[i] ^= a[i - 1];
        dp[i] = max(dp[i - 1], (~mx[a[i] ^ k] ? dp[mx[a[i] ^ k]] : -1) + 1);
        mx[a[i]] = i;
    }
    cout << *max_element(dp + 1, dp + n + 1);
    
    return 0;
}