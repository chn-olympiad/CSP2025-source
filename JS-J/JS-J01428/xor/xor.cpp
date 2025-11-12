#include<bits/stdc++.h>
#define maxn 500005
#define ll long long

int n, k;
int a[maxn], sum[maxn];
ll dp[maxn];

int main(){
    freopen("xor.in", "r", stdin); // xor6.in run for 100 seconds
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            if((sum[i] ^ sum[j]) == k) dp[i] = std::max(dp[i], dp[j] + 1);
            else dp[i] = std::max(dp[i], dp[j]);
            if(dp[i] - dp[j] > 2) break;
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}
