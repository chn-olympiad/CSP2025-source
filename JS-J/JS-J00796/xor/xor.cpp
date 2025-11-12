#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int a[maxn],dp[maxn],sum[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    if(a[1]==k)
        dp[1]=1;
    for(int i=2;i<=n;i++){
        int pos=0;
        for(int j=i;j>=1;j--){
            if(j==1){
                if(sum[i]==k){
                    pos=1;
                    break;
                }
            }
            else if((sum[i]^sum[j-1])==k){
                pos=j;
                break;
            }
        }
        if(pos!=0)
            dp[i]=max(dp[pos-1]+1,dp[i-1]);
        else
            dp[i]=dp[i-1];
    }
    cout<<dp[n]<<endl;
    return 0;
}
