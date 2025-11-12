#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    vector<long long>sum(n+1,0),v(n+1,-1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        sum[i] = a^sum[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            if((sum[j]^sum[i])==k){
                v[i]=i-j;
                break;
            }
        }
    }
    vector<long long>dp(n+1,0);
    for(int i=1;i<=n;i++){
        if(v[i]==-1)dp[i]=dp[i-1];
        else dp[i]=max(dp[i-1],dp[i-v[i]]+1);
    }
    cout<<dp[n];
    return 0;
}