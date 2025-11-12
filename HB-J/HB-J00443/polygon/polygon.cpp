#include<bits/stdc++.h>
using namespace std;
int n,a[5010],dp[5010],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 3;i <= n;i ++){
        for(int j = 1;j <= n - i;j ++){
            for(int k = 1;k <= i;k ++) dp[i] += a[k];
            if(dp[i] >= a[i] * 2) ans ++;
        }
    }
    cout << ans;
    return 0;
}
