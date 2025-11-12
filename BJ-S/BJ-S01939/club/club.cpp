#include <bits/stdc++.h>
using namespace std;
int t,n,dp[20][20][20],m,cnt,ans,c[5][100010],dp2[210][210];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        ans=0;
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>c[j][i];
                if(j!=1)
                    ans+=c[j][i];
                if(j==3)
                    cnt+=c[j][i];
            }

        }
        if(ans==0){
            sort(c[1],c[1]+1+n);
            for(int i=n/2+1;i<=n;i++)
                ans+=c[1][i];
            cout<<ans<<"\n";
            continue;
        }
        if(cnt==0){
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=m;j>=0;j--){
                    for(int k=m;k>=0;k--){
                            if(j>0)
                            dp2[j][k]=max(dp2[j][k],dp2[j-1][k]+c[1][i]);
                            if(k>0)
                            dp2[j][k]=max(dp2[j][k],dp2[j][k-1]+c[2][i]);

                    }
                }
            }
            for(int j=m;j>=0;j--){
                    for(int k=m;k>=0;k--){
                            ans=max(ans,dp2[j][k]);
                    }
                }
            cout<<ans<<"\n";
            continue;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                for(int k=m;k>=0;k--){
                    for(int l=m;l>=0;l--){
                        if(j>0)
                        dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+c[1][i]);
                        if(k>0)
                        dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+c[2][i]);
                        if(l>0)
                        dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+c[3][i]);
                    }
                }
            }
        }
        for(int j=m;j>=0;j--){
                for(int k=m;k>=0;k--){
                    for(int l=m;l>=0;l--){
                        ans=max(ans,dp[j][k][l]);
                    }
                }
            }
        cout<<ans<<"\n";
    }
    return 0;
}
