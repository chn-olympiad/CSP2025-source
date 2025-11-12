#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n,k,ans,arr[maxn],sum[maxn],dp[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=(sum[i-1]^arr[i]);
    }
    if(k==0){
        ll last=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==0) dp[i]=dp[i-1]+1;
            else{
                dp[i]=dp[i-1];
                if(last==0) last=i;
                else{
                    dp[i]=max(dp[i],dp[last]+1);
                    last=0;
                }
            }
        }
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    }
    else if(k==1){
        ll last=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==1) dp[i]=dp[i-1]+1;
            else{
                if(last==0) last=i;
                else{
                    dp[i]=max(dp[i-1],dp[last]+1);
                    last=0;
                }
            }
        }
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    }
    else if(n>10000){
        ll res=0;
        for(int i=1;i<=n;i++){
            for(int idx=i;idx<=n;idx++){
                if((sum[idx]^sum[i-1])==k){
                    res++;
                    i=idx;
                    break;
                }
            }
        }
    }
    else{
        for(int bg=1;bg<=n;bg++){
            ll res=0;
            for(int i=1;i<bg;i++){
                for(int idx=i;idx<bg;idx++){
                    if((sum[idx]^sum[i-1])==k){
                        res++;
                        i=idx;
                        break;
                    }
                }
            }
            for(int i=bg;i<=n;i++){
                for(int idx=i;idx<=n;idx++){
                    if((sum[idx]^sum[i-1])==k){
                        res++;
                        i=idx;
                        break;
                    }
                }
            }
            ans=max(ans,res);
        }
    }
    cout<<ans;
    return 0;
}
