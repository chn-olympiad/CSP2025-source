#include<bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5+10;
//int a1[N], a2[N], a3[N], dp[205][205][205];
struct node{
    int a1, a2, a3;
}a[N];
bool cmp(node x, node y){
    return max(x.a1, x.a2) > max(y.a1, y.a2);
}
bool cmp1(node x, node y){
    return x.a1 > x.a2;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        bool flag2 = true, flag3 = true;
        for(int i=1; i<=n; i++){
            scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
            if(a[i].a2) flag2 = false;
            if(a[i].a3) flag3 = false;
        }
        int ans = 0;
        /*for(int i=1; i<=n/2; i++){
            for(int j=1; j<=n/2; j++){
                for(int k=1; k<=n/2; k++){
                    if(i+j+k > n)break;
                    dp[i][j][k] = max(max(dp[i-1][j][k]+a1[i], dp[i][j-1][k]+a2[j]), dp[i][j][k-1]+a3[k]);
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }*/
        if(flag2){
            sort(a+1, a+1+n, cmp1);
            for(int i=1; i<=n/2; i++){
                ans += a[i].a1;
            }
            printf("%d\n", ans);
        }
        else if(flag3){
            /*int cnt1=0, cnt2=0;
            sort(a+1, a+1+n, cmp);
            for(int i=1; i<=n; i++){
                if(cnt1 > n/2){
                    ans += a[i].a2;
                    continue;
                }
                else if(cnt2 > n/2){
                    ans += a[i].a1;
                    continue;
                }
                if(a[i].a1 > a[i].a2){
                    cnt1++;
                    ans += a[i].a1;
                }
                else{
                    cnt2++;
                    ans += a[i].a2;
                }
            }
            printf("%d\n", ans);
        }*/
        sort(a+1, a+1+n, cmp);
        int dp[N][N];
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=n+1; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n/2; j++){
                dp[i][j] = dp[i-1][j-1]+max(a[i].a1, a[i].a2);
            }
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}