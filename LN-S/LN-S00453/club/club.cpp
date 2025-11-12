#include <bits/stdc++.h>
using namespace std;
int n, t, a, b, c, dp[505][505][505], mx;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a >> b >> c;
            for (int j=i;j>=0;j--){
                for (int k=i;k>=0;k--){
                    for (int l=i;l>=0;l--){
                        int aa=a, bb=b, cc=c;
                        if (j==0) aa = 0;
                        if (k==0) bb = 0;
                        if (l==0) cc = 0;
                        dp[j][k][l] = max(max(dp[j][k][max(l-1,0)]+cc,dp[max(j-1,0)][k][l]+aa),dp[j][max(k-1,0)][l]+bb);
                    }
                }
            }
        }
        for (int j=n/2;j>=0;j--){
            for (int k=n/2;k>=0;k--){
                for (int l=n/2;l>=0;l--){
                    mx = max(mx,dp[j][k][l]);
                }
            }
        }
        cout << mx << endl;
        memset(dp,0,sizeof(dp));
        mx = 0;
    }
    return 0;
}
