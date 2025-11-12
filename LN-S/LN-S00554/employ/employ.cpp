#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int t,n;
int a[maxn],b[maxn],c[maxn];
int cnt1=1,cnt2=1,cnt3=1;
int dp[maxn][2][2][2][maxn/2];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i] >> b[i] >> c[i];
        for(int i = 1; i <= n; i++){
            dp[i][1][0][0]= a[i];
            dp[i][0][1][0] = b[i];
            dp[i][0][0][1] = c[i];
        }
        for(int i = 2; i <= n; i++){
                 if(cnt1 < n/2 ){
                     dp[i][1][0][0][p] = max(dp[i][1][0][0],max(dp[i-1][0][1][0],max(dp[i-1][1][0][0],dp[i-1][0][0][1]))+a[i]); cnt1++;
                }
                 if(cnt2 < n/2){
                    dp[i][0][1][0] = max(dp[i][0][1][0],max(dp[i-1][0][1][0],max(dp[i-1][1][0][0],dp[i-1][0][0][1]))+b[i]);
                    cnt2++;
                }
                if(cnt3 < n/2){
                    dp[i][0][0][1] = max(dp[i][0][0][1],max(dp[i-1][0][1][0],max(dp[i-1][1][0][0],dp[i-1][0][0][1]))+c[i]); cnt3++;

            }
        }
        cout << max(dp[n][1][0][0],max(dp[n][0][1][0],dp[n][0][0][1])) << endl;
        for(int i = 1; i <= n; i++){
            cout << dp[i][1][0][0] << " " << dp[i][0][1][0] << " " << dp[i][0][0][1] << endl;
        }
        cout << "like" << endl;
    }
    return 0;


}
