#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
int a[maxn],n,dp[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        int sum = 0;

        for(int j = 1;j<=i;j++)
            sum += a[j];
        if(sum <= a[i]*2)
            continue;
        int target = sum-a[i]*2;
        for(int k = i;k>=1;k--){
            if(target - a[k] >= 0){
                dp[target-1] += dp[target-1-a[k]]+1;
            }
        }
        ans += dp[target-1] % mod;
    }
    cout << ans;
    return 0;
}
