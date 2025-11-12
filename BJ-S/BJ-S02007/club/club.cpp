#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,d1[100005],d2[100005],d3[100005],dp[201][101][101],f[100005];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        int ans=0;
        bool ma1=1,ma2=1,ma3=1;
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d1[i]>>d2[i]>>d3[i];
            if(d1[i]!=0){
                ma1=0;
            }
            if(d2[i]!=0){
                ma2=0;
            }
            if(d3[i]!=0){
                ma3=0;
            }
        }
        if(n==2){
            ans=max({d1[1]+d2[2],d1[1]+d3[2],d2[1]+d1[2],d2[1]+d3[2],d3[1]+d1[2],d3[1]+d2[2]});
            cout<<ans<<'\n';
            continue;
        }
        if(ma3){
            if(ma2){
                sort(d1+1,d1+n+1);
                for(int i=n;i>n/2;i--){
                    ans+=d1[i];
                }
                cout<<ans<<'\n';
                continue;
            }
            if(ma1){
                sort(d2+1,d2+n+1);
                for(int i=n;i>n/2;i--){
                    ans+=d2[i];
                }
                cout<<ans<<'\n';
                continue;
            }
            else{
                dp[1][1][0]=d1[1];
                dp[1][0][1]=d2[1];
                for(int i=2;i<=n;i++){
                    for(int j=0;j<=min(i,n/2);j++){
                        if(i-j>n/2){
                            continue;
                        }
                        dp[i][j][i-j]=max(dp[i-1][j][i-j-1]+d2[i],dp[i-1][j-1][i-j]+d1[i]);
                        f[i]=max(dp[i][j][i-j],f[i]);
                    }
                }
                cout<<f[n]<<'\n';
                continue;
            }
        }
        dp[1][1][0]=d1[1];
        dp[1][0][1]=d2[1];
        dp[1][0][0]=d3[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<=min(i,n/2);j++){
                for(int k=0;k<=min(i,n/2);k++){
                    if(i-j-k>n/2){
                        continue;
                    }
                    dp[i][j][k]=max({dp[i-1][j][k]+d3[i],dp[i-1][j][k-1]+d2[i],dp[i-1][j-1][k]+d1[i]});
                    f[i]=max(dp[i][j][k],f[i]);
                }
            }
        }
        cout<<f[n]<<'\n';
    }
    return 0;
}