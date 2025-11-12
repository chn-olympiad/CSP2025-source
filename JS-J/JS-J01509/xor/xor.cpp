#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],t=0,ans=0,dp[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0 || a[i]==1){
            t++;
        }
    }
    if(n==t){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    else{
        for(int i=1,j=0;i<=n;i++){
            dp[i]=dp[i-1];
            if(a[i]==k){
                dp[i]=dp[i-1]+1;
                j=i;
            }
            else{
                t=a[i];
                for(int g=i-1;g>j;g--){
                    t^=a[g];
                    if(t==k){
                        dp[i]=dp[i-1]+1;
                        j=i;
                    }
                }
            }
        }
    }
    cout<<dp[n];
    return 0;
}
