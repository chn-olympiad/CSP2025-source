#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=500000;
LL n,k;
LL a[N+5];
LL dp[N+5];
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
                //cout<<i<<' '<<j<<' '<<(a[j-1]^a[i])<<'\n';
            if((a[j-1]^a[i])==k){
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }

    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
