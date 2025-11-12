#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans=0,dp[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            a[i]=a[i]^a[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=1;j<=i;j++){
            int x;
            if(j==1){
                x=a[i];
            }
            else{
                x=a[i]^a[j-1];
            }
            if(x==k){
                //cout<<i<<' '<<j<<endl;
                dp[i]=max(dp[j-1]+1,dp[i]);
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<dp[i]<<' ';
    //}
    //cout<<endl;
    cout<<dp[n];
    return 0;
}
