#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[500005],a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long l=a[i];
        dp[i]=dp[i-1];
        if(l==k)
            dp[i]++;
        for(int j=i-1;j>0;j--){
            l=a[j]^l;
            if(l==k){
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}


