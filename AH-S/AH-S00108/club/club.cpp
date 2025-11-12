#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100010][3];
int dp[201][101][101];
int ans;int dp2[50010];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>T;
while(T--){
cin>>n;
ans=-1;
for(int i=1;i<=n;i++){
cin>>a[i][0]>>a[i][1]>>a[i][2];
}
if(n>500){
    for(int i=1;i<=n;i++){
        for(int j=0;;j++){
            if(j>i || j>n/2)continue;
            if(j)dp2[j]=max(dp2[j]+a[i][1],dp2[j-1]+a[i][0]);
            else dp2[j]=dp2[j]+a[i][1];
        }
    }
    cout<<dp2[n/2];
    return 0;
}
for(int x=1;x<=n;x++){
    for(int i=0;i<=x;i++){
            if(i>n/2)break;
        for(int j=0;j<=x-i;j++){
            if(j>n/2)break;
            if(x-i-j>n/2)continue;
            if(i){
                dp[x][i][j]=max(dp[x][i][j],dp[x-1][i-1][j]+a[x][0]);
            }
            if(j){
                dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j-1]+a[x][1]);
            }
            if(x-i-j>0){
                dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j]+a[x][2]);
            }
            ans=max(ans,dp[x][i][j]);
        }
    }
}
/*for(int i=0;i<=n/2;i++){
    for(int j=0;j<=n/2;j++){
        if(i+j<n/2)continue;
        ans=max(ans,dp[n][i][j]);
    }
}*/
memset(dp,0,sizeof(dp));
cout<<ans<<endl;
}

return 0;}
//Ren5Jie4Di4Ling5%
