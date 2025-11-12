#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int dp[500005];
int main() {
    freopen("xor.in","r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == k) dp[i] = dp[i-1]+1;
        else{
            dp[i] = dp[i-1];
            int num = a[i];
            for(int j = i-1;j >= 1;j--){
                num ^= a[j];
                if(dp[j-1]+1 <= dp[i-1])break;
                if(num == k){
                    dp[i] = dp[j-1]+1;
                }
            }
        }

    }
    //for(int i = 1;i <= n;i++) cout << dp[i] << " ";
    //cout << endl;
    cout << dp[n] << endl;
    return 0;
}
