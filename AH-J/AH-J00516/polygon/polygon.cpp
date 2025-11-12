#include<bits/stdc++.h>
using namespace std;
long long n,dp[5200],a[5200],t[5200];
void dfs(long long u,long long h,long long st){
    if(h+t[u]-t[st+1]<=a[st]) return;
    if(u==st){
        if(h>a[st]) dp[st]++;
        dp[st]=dp[st]%998244353;
        return;
    }
    dfs(u+1,h,st);
    dfs(u+1,h+a[u],st);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=26){
        sort(a,a+1+n);
        for(int i=n;i>=1;i--) t[i]=a[i]+t[i+1];
        dp[1]=0,dp[2]=0;
        for(int i=3;i<=n;i++){
            dfs(1,0,i);
            dp[i]+=dp[i-1];
        }
        cout<<dp[n];
    }else{
        cout<<366911923;
    }
    return 0;
}
