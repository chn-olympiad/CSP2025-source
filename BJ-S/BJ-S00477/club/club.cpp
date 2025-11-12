#include<bits/stdc++.h>
using namespace std;
int n;
int a[55],b[55],c[55];
int dp[55][55][55];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int lim=n/2;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int m=n;m>=0;m--){
                for(int k=0;k<=m&&k<=lim;k++){
                    for(int l=0;l<=m&&l<=lim;l++){
                        int j=m-k-l;
                        if(j>lim||j<0)continue;
                        if(j>0)dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i]);
                        if(k>0)dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+b[i]);
                        if(l>0)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+c[i]);
                        //cout<<i<<' '<<a[i]<<' '<<b[i]<<' '<<c[i]<<'\n'<<j<<' '<<k<<' '<<l<<' '<<dp[j][k][l]<<'\n';
                    }
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=lim;i++)
            for(int j=1;j<=lim;j++){
                int k=n-i-j;
                if(k>lim)continue;
                ans=max(ans,dp[i][j][k]);
            }
        cout<<ans<<'\n';
    }
}
