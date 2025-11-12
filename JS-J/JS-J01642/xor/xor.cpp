#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool ps=false;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],ps|=(a[i]>1);
    if(!ps){
        if(k==0){
            int ans=0,ans1=0;
            for(int i=1;i<n;i++){
                if(a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }
                ans1+=a[i]^1;
            }
            cout<<ans+ans1<<endl;
            return 0;
        }else if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++) ans+=a[i];
            cout<<ans<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int sum=0;
        for(int j=i;j>=1;j--){
            sum^=a[j];
            if(sum==k){
                dp[i]=max(dp[i],dp[j-1]+1);
                break;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}