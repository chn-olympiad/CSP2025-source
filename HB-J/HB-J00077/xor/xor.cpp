#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005],sum[500005],dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]^sum[i-1];
    }
    for(int r=1;r<=n;r++){
        for(int len=0;len<=r;len++){
            int l=r-len;
            dp[r]=max(dp[r],((sum[r]^sum[l-1])==k)+dp[l-1]);
        }
    }
    cout<<dp[n];
    return 0;
}
