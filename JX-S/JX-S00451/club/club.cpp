#include <bits/stdc++.h>
using namespace std;
int t, n, dp[100005][3], f[100005], num1, num2, num3;
bool flag1, flag2, flag3;
struct node {
    int x, y, z;
}a[100005];
bool cmp(node a, node b) {
    int c1=max({a.x, a.y, a.z}), c2=max({b.x, b.y, b.z});
    return c1>c2;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while (t--) {
        cin>>n;
        flag1=flag2=flag3=0;
        num1=num2=num3=0;
        memset(dp, 0, sizeof dp);
        memset(f, 0, sizeof f);
        for (int i=1; i<=n; i++) cin>>a[i].x>>a[i].y>>a[i].z;
        sort(a+1, a+1+n, cmp);
        for (int i=1; i<=n; i++) {
            if (num3+1 <= n/2) {
                if (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].z > f[i]) {
                    f[i]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].z;
                    flag3=1;
                }
            }
            if (num2+1 <= n/2) {
                if (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].y > f[i]) {
                    f[i]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].y;
                    flag2=1;
                }
            }
            if (num1+1 <= n/2) {
                if (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].x > f[i]) {
                    f[i]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+a[i].x;
                    flag1=1;
                }
            }
            if (flag1) {
                flag2=flag3=0;
                num1++;
                dp[i-1][1]+=a[i].x;
            }else if (flag2) {
                flag3=0;
                num2++;
                dp[i-1][2]+=a[i].y;
            }else {
                num3++;
                dp[i-1][3]+=a[i].z;
            }
        }
        long long ans=0;
        for (int i=1; i<=n; i++) ans+=f[i];
        cout<<ans<<"\n";
    }
    return 0;
}
