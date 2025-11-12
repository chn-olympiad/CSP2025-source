#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005];
int qxor(int l,int r) {
    return sum[r]^sum[l-1];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (i > 1) sum[i] = (a[i]^sum[i-1]);
        else sum[1] = a[1];
    }
    int dp[500005];
    dp[0] = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            dp[i] = max(dp[i],dp[j]+(qxor(j+1,i)==k));
        }
    }
    cout << dp[n];
    return 0;
}
