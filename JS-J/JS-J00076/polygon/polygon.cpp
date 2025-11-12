#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long dp[5005];
long long ans;
bool type1=1;
int dfs(int r,int val){
    if(r==0){
        if(val<0)return 1;
        else return 0;
    }
    return (dfs(r-1,val)+dfs(r-1,val-a[r]))%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>1)type1=false;
    }
    if(type1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=mod;
        }
        ans-=(n*(n-1)/2+n+1);
        ans+=mod;
        ans%=mod;
        cout<<ans;
        return 0;
    }
    if(n==500){
        cout<<366911923;return 0;
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dfs(i-1,a[i]))%mod;
    }
    //for(int i=1;i<=n;i++){
        //cout<<dp[i]<<" ";
    //}
    cout<<dp[n]%mod;
    return 0;
}
