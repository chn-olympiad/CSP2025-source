#include <bits/stdc++.h>
using namespace std;
int dp[100010][3];
int a1[100010],a2[100010],a3[100010];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(dp,0,sizeof(dp));
        int n;
        int n1=n/2,n2=n/2,n3=n/2;
        scanf("%d",&n);
        for (int i = 1;i <= n;i++) {
            scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
            int a = (n1>0 ? (dp[i-1][0]+a1[i-1]) : dp[i-1][0]);
            int b = (n2>0 ? (dp[i-1][1]+a2[i-1]) : dp[i-1][1]);
            int c = (n3>0 ? (dp[i-1][2]+a3[i-1]) : dp[i-1][2]);
            int mx = max(a,max(b,c));
            if (mx == dp[i-1][0] + a1[i-1] && n1) dp[i][0] = mx,n1--;
            else if (mx == dp[i-1][1] + a2[i-1] && n2) dp[i][1] = mx,n2--;
            else dp[i][2] = mx,n3--;
        }
        printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
    }
    return 0;
}
