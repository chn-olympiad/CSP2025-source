#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,k;
bool fa=1,fb=1;
ll a[N],sum[N],dp[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=1)fa=0;
        if(a[i]>1)fb=0;
        sum[i]=sum[i-1]^a[i];
    }
    if(fa==1){
        cout<<n/2;
        return 0;
    }
    if(fb==1){
        if(k==1){
            ll cnt=0;
            for(ll i=1;i<=n;i++){
                if(a[i]==1)++cnt;
            }
            cout<<cnt;
        }
        else{
            ll cnt=0,cnt1=0;
            for(ll i=1;i<=n;i++){
                if(a[i]==0)cnt++;
                else cnt1++;
            }
            cout<<cnt+cnt1/2;
        }
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            if(dp[i-j]<dp[i-1])break;
            if(sum[i]^sum[i-j]==k){
                dp[i]=dp[i-j]+1;
                break;
            }
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n];
    return 0;
}
/*
PLEASE AC!!!!!!!!!!
*/
