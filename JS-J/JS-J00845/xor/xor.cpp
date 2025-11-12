#include <bits/stdc++.h>
using namespace std;

long long dp[500005];
long long a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i-1];
        if(a[i] == k){
            dp[i] = dp[i-1]+1;
            continue;
        }
        long long tmp=0;
        for(int j = i;j >= 1;j--){
            if(dp[j] - dp[j-1] >= 1){
                break;
            }
            tmp ^= a[j];
            if(tmp == k){
                dp[i] = dp[i-1]+1;
                break;
            }
        }
    }
    cout << dp[n];
    return 0;
}
