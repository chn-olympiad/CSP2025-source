#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 200 + 5;
int a[N][5];
int a2[100005];
int dp[N][N][N];
bool cmp(int a,int b){
    return a > b;
}
void A(int n){
    for(int i = 1; i <= n; ++i){
        int v;
        cin >> a2[i] >> v >> v;
    }
    int ans = 0;
    sort(a2+1,a2+n+1,cmp);
    for(int i = 1; i <= n/2; ++i){
        ans += a2[i];
    }
    cout << ans;
}
void solve(){
    cin >> n;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    if(n > 200){
        A(n);
        return;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
        }
    }
    for(int m = 1; m <= n; ++m){
        for(int i = 0; i < min(m,n/2+1); ++i){
            for(int j = 0 ; j < min(m - i,n/2+1); ++j){
                int k = m - i - j - 1;
                if(k > n/2)continue;
                dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k] + a[m][0]);
                dp[i][j+1][k] = max(dp[i][j+1][k],dp[i][j][k] + a[m][1]);
                dp[i][j][k+1] = max(dp[i][j][k+1],dp[i][j][k] + a[m][2]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n/2; ++i){
        for(int j = 0; j <= n/2; ++j){
            int k = n - i - j;
            if(k<0 || k > n/2)continue;
            ans = max(ans,dp[i][j][k]);
        }
    }
    cout << ans << '\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
