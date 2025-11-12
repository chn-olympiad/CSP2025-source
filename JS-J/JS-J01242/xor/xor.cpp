#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[555555],dp[555555];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]^a[i]==k) dp[j]=dp[i]+1;
            else dp[j]=0;
        }
    }
    cout<<dp[n];
    return 0;
}
