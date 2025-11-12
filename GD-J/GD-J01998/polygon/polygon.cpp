#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
using big = long long;
const long long mod = 998244353;

int a[5005],fi[5005],n;
long long dp[10105];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!fi[a[i]])fi[a[i]]=i;
    }
    fi[5001]=n+1;
    for(int i=5000;i>=1;i--){
        if(!fi[i])fi[i]=fi[i+1];
    }
    dp[0]=1;
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=5001+a[i];j>=a[i];j--){
            ans+=1LL*dp[j-a[i]]*max(fi[min(j,5001)]-i-1,0)%mod;
            ans%=mod;
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
        for(int j=5001+a[i];j>=5002;j--){
            dp[j-1]=(dp[j-1]+dp[j])%mod;
            dp[j]=0;
        }
    }
    cout<<ans;
    return 0;
}
