#include<bits/stdc++.h>
using namespace std;
int t,n,ans,s[210][3],dp[210][110][110];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        if(n<=200){
            memset(dp,0,sizeof(dp));
            ans=0;
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>s[i][0]>>s[i][1]>>s[i][2];
            }
            for(int i=1;i<=n;i++){
                for(int a=0;a<=i;a++){
                    for(int b=0;b<=i-a;b++){
                        if(a>n/2||b>n/2||i-a-b>n/2){
                            continue;
                        }
                        if(a>0){
                            dp[i][a][b]=max(dp[i][a][b],dp[i-1][a-1][b]+s[i][0]);
                        }
                        if(b>0){
                            dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b-1]+s[i][1]);
                        }
                        if(i-a-b>0){
                            dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b]+s[i][2]);
                        }
                    }
                }
            }
            for(int a=0;a<=n;a++){
                for(int b=0;b<=n-a;b++){
                    ans=max(ans,dp[n][a][b]);
                }
            }
            cout<<ans<<'\n';
        }else{
            int t[100010];
            for(int i=1;i<=n;i++){
                int x,y;
                cin>>t[i]>>x>>y;
            }
            sort(t+1,t+n+1);
            long long ans=0;
            for(int i=n;i>=n/2+1;i--){
                ans+=t[i];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
