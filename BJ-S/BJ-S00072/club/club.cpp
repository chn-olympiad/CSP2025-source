#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[100005][5];
int dp[50005][5];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        for (int i=1;i<=n/2;i++) dp[i][1]=dp[i][2]=dp[i][3]=0;
        for (int i=1;i<=n;i++){
            for (int k=n/2;k>=1;k--){
                int d=dp[k][1],b=dp[k][2],c=dp[k][3];
                int tot=min(k,i);
                int d2=dp[tot][1],b2=dp[tot][2],c2=dp[tot][3];
                //dp[k][1]=max(max(max(dp[k-1][1]+a[i][1],dp[k]),max(dp[k-1][2]+a[i][2],dp[k])),max(dp[k-1]+a[i][3],dp[k]));
                dp[k][1]=max(d,max(dp[k-1][1],max(b2,c2))+a[i][1]);
                dp[k][2]=max(b,max(dp[k-1][2],max(d2,c2))+a[i][2]);
                dp[k][3]=max(c,max(dp[k-1][3],max(d2,b2))+a[i][3]);
                /*dp[k][1]=max(d,dp[k-1][1]+a[i][1])+b+c;
                dp[k][2]=max(b,dp[k-1][2]+a[i][2])+d+c;
                dp[k][3]=max(c,dp[k-1][3]+a[i][3])+d+b;*/
            }
            //cout << dp[n/2-1][1] << " " << dp[n/2-1][2] << " " << dp[n/2-1][3] << endl;
        }
        cout << max(max(dp[n/2][1],dp[n/2][2]),dp[n/2][3]) << endl;
    }
    return 0;
}
