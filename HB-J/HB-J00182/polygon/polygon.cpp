#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],ans;
unordered_map <int,int> dp,dp1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    dp[0]=1;
    for (int i=1;i<=n;i++){
        dp1=dp;
        for (pair <int,int> j:dp1){
            dp[j.first+a[i]]+=j.second;
            dp[j.first+a[i]]%=mod;
            if (j.first+a[i]>(a[i]*2)) ans=(ans+j.second)%mod;
        }
    }
    cout<<ans;
    return 0;
}
