#include<bits/stdc++.h>
using namespace std;//75-95
//big example all AC
const int N = 5e5 + 5;
const int SUBC = 256;
int a[N], sum[N], dp[N], p[SUBC];
int n, k, ans = 0;
inline void dfs(int x, int cnt){
    if(x > n){
        ans = max(ans, cnt);
        return ;
    }
    for(int j = x; j <= n; j++){
        if((sum[j] ^ sum[x - 1]) == k){
            dfs(j + 1, cnt + 1);
            ans = max(ans, cnt + 1);
            break;
        }
    }
    dfs(x + 1, cnt);
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sum[i] = (sum[i - 1] ^ a[i]);
    bool subB = 1;
    for(int i = 1; i <= n; i++)
        if(a[i] > 1) subB = 0;
    if(k > 1) subB = 0;
    if(subB){
        int l = 0, r = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 1) r++;
            else l++;
        }
        if(k == 1) cout << r << "\n";
        else cout << l << "\n";
        return 0;
    }
    memset(dp, 0, sizeof dp);
    if(a[1] == k) dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1];
        for(int j = i; j >= 1; j--){
            if(dp[j - 1] ^ dp[i]) break;
            if((sum[i] ^ sum[j - 1]) == k) dp[i]++;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
