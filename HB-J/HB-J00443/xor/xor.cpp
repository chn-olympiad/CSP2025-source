#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(a[i] == k) ans ++;
        else{
            dp[i + 1] == a[i] ^ dp[i];
            if(dp[i + 1] == k){
                ans ++;
                dp[i + 1] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
