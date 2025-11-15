#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e9 + 7;

void cal(){
    int n;
    bool A=1, B=1, C=1;
    int a[5][100005];
    cin >> n;
    for(int i=1 ;i<=n; i++){
        cin >> a[1][i] >> a[2][i] >> a[3][i];
        if(a[2][i] != 0 || a[3][i] != 0) A=0;
        if(a[3][i] != 0) B=0;
    }
    if(A){
        sort(a[1]+1, a[1]+1+n);
        int sum = 0;
        for(int i=n; i>n/2; i--){
            sum += a[1][i];
        }
        cout << sum << '\n';
    }else if(n<=10){
        int dp[15][8][8][8];
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n/2; j++){
                for(int k=0; k<=n/2; k++){
                    for(int l=0; l<=n/2; l++){
                        dp[i][j][k][l] = -INF;
                    }
                }
            }
        }
        dp[0][0][0][0] = 0;
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n/2; j++){
                for(int k=0; k<=n/2; k++){
                    int l = i-j-k-1, tmp = dp[i-1][j][k][l];
                    if(l>=0 && tmp != -INF){
                        dp[i][j+1][k][l] = (j<n/2)? tmp + a[1][i]: -INF;
                        dp[i][j][k+1][l] = (k<n/2)? tmp + a[2][i]: -INF;
                        dp[i][j][k][l+1] = (l<n/2)? tmp + a[3][i]: -INF;
                        ans = max(ans, max(dp[i][j+1][k][l], max(dp[i][j][k+1][l], dp[i][j][k][l+1])));
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}

int32_t main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        cal();
    }

    return 0;
}