#include<bits/stdc++.h>
using namespace std;
long long dp[5010],a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=3;j--){
            dp[j]=max(dp[j],dp[j]+1)%998244353;
        }
    }
    cout<<dp[n]%998244353;
    return 0;
}
