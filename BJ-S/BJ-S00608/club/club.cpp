#include <bits/stdc++.h>
using namespace std;
int a[100005][3], dp[205][205][205];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Ti=0; Ti<T; ++Ti){
        int n, maxp, ans=0;
        scanf("%d", &n);
        maxp=n/2;
        for (int i=1; i<=n; ++i)
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        for (int a1=0; a1<=maxp; ++a1){
            for (int a2=0; a2<=min(n-a1, maxp); ++a2){
                for (int a3=0; a3<=min(n-a1-a2, maxp); ++a3){
                    dp[a1][a2][a3]=0;
                    if (a1>0) dp[a1][a2][a3]=max(dp[a1][a2][a3], dp[a1-1][a2][a3]+a[a1+a2+a3][0]);
                    if (a2>0) dp[a1][a2][a3]=max(dp[a1][a2][a3], dp[a1][a2-1][a3]+a[a1+a2+a3][1]);
                    if (a3>0) dp[a1][a2][a3]=max(dp[a1][a2][a3], dp[a1][a2][a3-1]+a[a1+a2+a3][2]);
                    if (a1+a2+a3==n) ans=max(ans, dp[a1][a2][a3]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
