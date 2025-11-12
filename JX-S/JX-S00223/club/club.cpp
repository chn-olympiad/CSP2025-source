#include<bits/stdc++.h>
using namespace std;

const int N = 1E6 + 10;
int a[N][4];
int dp[N][4];
int t;
int ans = INT_MIN;
int n;
/*
int threemax(int x, int y, int z){
    return max(x, max(y, z));
}
*/
void dfs(int i, int fcnt, int scnt, int tcnt, int sum){
    if(i > n){
        ans = max(ans, sum);
        return ;
    }
    if(fcnt + 1 <= n / 2) dfs(i + 1, fcnt + 1, scnt, tcnt, sum + a[i][1]);
    if(scnt + 1 <= n / 2) dfs(i + 1, fcnt, scnt + 1, tcnt, sum + a[i][2]);
    if(tcnt + 1 <= n / 2) dfs(i + 1, fcnt, scnt, tcnt + 1, sum + a[i][3]);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = INT_MIN;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(1, 0, 0, 0, 0);
        /*
        for(int i = 1;i <= n;i++){
            dp[i][1] = threemax(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + a[i][1];
            dp[i][2] = threemax(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + a[i][2];
            dp[i][3] = threemax(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + a[i][3];
        }*/
        cout << ans << "\n";
    }
    return 0;

}
