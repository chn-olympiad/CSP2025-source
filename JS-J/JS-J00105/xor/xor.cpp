#include<bits/stdc++.h>
using namespace std;
int dp[500001][256],n,k,a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=255;i++){
        dp[0][i]=-10000000;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<256;j++){
            dp[i][j]=dp[i-1][j^a[i]];
        }
        for(int j=0;j<256;j++)
        {
            if(j==k){
                dp[i][0]=max(dp[i][0],dp[i][j]+1);
            }
            else{
                dp[i][0]=max(dp[i][0],dp[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<256;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    return 0;
}