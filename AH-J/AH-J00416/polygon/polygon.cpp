#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5010];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0] = 1;
    int ans;
    ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = a[i]+1;j<=5001;j++){
            ans = (ans+dp[j])%998244353;
        }
        for(int j = 5001;j>=0;j--){
            if(!dp[j]){
                continue;
            }
            if(j == 5001){
                dp[j] = dp[j]*2%998244353;
            }else if(j+a[i]>5000){
                dp[5001] = (dp[5001]+dp[j])%998244353;
            }else{
                dp[j+a[i]] = (dp[j+a[i]]+dp[j])%998244353;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
