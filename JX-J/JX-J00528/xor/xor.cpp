#include <iostream>
#include <cstring>
using namespace std;
int n, k;
const int N = 5e5 + 5;
const int M = 1.5e6 + 5;
int a[N], vis[N], la[N];
int dp[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    memset(la, -1, sizeof(la));
    memset(vis, -1, sizeof(vis));
    vis[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
        if(vis[a[i] ^ k] != -1) la[i] = vis[a[i] ^ k];
        vis[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i - 1];
        if(la[i] != -1){
            dp[i] = max(dp[la[i]] + 1, dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}
