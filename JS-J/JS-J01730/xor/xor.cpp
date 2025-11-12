#include<bits/stdc++.h>
using namespace std;
int a[500005], q[10005][10005], dp[10005][10005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, onenum = 0, zeronum = 0, ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(a[i] == 1) onenum++;
        if(a[i] == 0) zeronum++;
    }
    if(onenum == n && k == 0){
        ans = n / 2;
        printf("%d", ans);
        return 0;
    }
    if(onenum + zeronum == n){
        if(k == 1){
            printf("%d", onenum);
            return 0;
        }
        if(k == 0){
            for(int i = 1; i <= n; i++){
                if(a[i] == 1 && a[i - 1] == 1)
                    ans++, i++;
            }
            ans += zeronum;
            printf("%d", ans);
        }
    }
    for(int i = 1; i <= n; i++)
        q[1][i] = q[1][i - 1] xor a[i];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++) q[i][j] = -1;
        for(int j = i; j <= n; j++)
            q[i][j] = q[i - 1][j] xor q[i - 1][i - 1];
    }
    for(int i = 1; i <= n; i++){
        dp[i][i - 1] = dp[i - 1][i];
        for(int j = i; j <= n; j++){
            if(q[i][j] == k && q[i - 1][j] != k)
                dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j - 1]);
            else dp[i][j] = dp[i][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
}
