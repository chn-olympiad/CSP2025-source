#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],dp[N][5],h[N][5][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t--){
        memset(dp,0,sizeof(dp));
        memset(h,0,sizeof(h));
        scanf("%d",&n);
        int p=n/2;
        for (int i=1;i<=n;i++)
            scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=3;j++){
                for (int k=1;k<=3;k++){
                    if (h[i-1][j][k]+1<=p){
                        if (dp[i-1][k]+a[i][j]>dp[i][j]){
                            dp[i][j]=dp[i-1][k]+a[i][j];
                            h[i][j][k]=h[i-1][j][k]+1;
                        }
                    }
                }
            }
        }
        int ma=max(dp[n][1],max(dp[n][2],dp[n][3]));
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<'\n';
    }
    return 0;
}
