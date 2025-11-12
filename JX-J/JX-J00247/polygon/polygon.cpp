#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5e3+5;
int n,ans,y=1;
int a[N],dp[N*N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) y=0; 
    }
    if(y){
        long long ans=1;
        for(int i=1;i<=n;i++) (ans*=2ll)%=mod;
        (ans+=mod-n-1ll)%mod;
        (ans+=(mod-(n-1ll)*n/2))%=mod;
        cout<<(ans%mod+mod)%mod;
    }
    else{
        int maxn=-1;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=maxn;j>0;j--){
                if(dp[j]){
                    (dp[j+a[i]]+=dp[j])%=mod;
                    if(j>a[i]){
                        (ans+=dp[j])%=mod;
                    } 
                    maxn=max(maxn,j+a[i]);
                }
            }
            for(int j=1;j<i;j++){
                dp[a[i]+a[j]]++;
                maxn=max(maxn,a[j]+a[i]);
            } 
        }
        cout<<ans%mod;
    }
    return 0;
}