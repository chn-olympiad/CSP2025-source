#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
const int M = 1e3;
int n,k;
int a[N + 5],o[N + 5];
int dp[M + 5][M + 5];
signed main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    o[1] = a[1];
    for(int i = 2 ; i <= n ; i ++)
        o[i] = o[i - 1] ^ a[i];
    for(int i = 1 ; i <= n ; i ++)
        for(int j = i ; j <= n ; j ++)
            if((o[j] ^ o[i - 1]) == k)
                dp[i][j] = 1;
    for(int k = 2 ; k <= n ; k ++) {
        for(int i = 1 ; i <= n - k + 1 ; i ++) {
            for(int j = 1 ; j < k ; j ++) {
                dp[i][i + k - 1] = max(dp[i][i + k - 1],dp[i][i + j] + dp[i + j + 1][i + k - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}

