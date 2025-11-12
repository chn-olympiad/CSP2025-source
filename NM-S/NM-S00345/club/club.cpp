#include<bits/stdc++.h>
using namespace std;
int t;
int dp[100005][3],a[100005];
long long ans;
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int xn=n/2;
        for(int i=1;i<=n;i++){
            cin>>dp[i][1]>>dp[i][2]>>dp[i][3];
            if(dp[i][2]==dp[i][3]==dp[n][3]&&dp[i][2]==0){
                for(int j=1;i<=n;j++){
                    a[j]=dp[i][1];
                }
                sort(a+1,a+n+1);
                for(int w=xn;w>0;w++){
                    ans+=a[w];
                }
            }
        }
        if(n==2){
            ans=max(dp[1][1]+dp[2][2],max(dp[1][1]+dp[2][3],max(dp[1][2]+dp[2][1],max(dp[2][3]+dp[1][2],max(dp[1][3]+dp[2][1],dp[1][3]+dp[2][2])))));
        }

        for(int j=1;j<=3;j++){
            for(int i=1;i<=n;i++){
            }
        }
        cout<<ans;
    }
    return 0;
}
