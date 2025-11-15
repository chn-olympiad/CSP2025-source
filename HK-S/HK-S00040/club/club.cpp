#include <bits/stdc++.h>
using namespace std;

#define N 500

int dp[N][N][N];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie();
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        if(n > 500){
            continue;
        }
        int res = -1;
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        for(int i = 0; i < n; i++)
            for(int ia = n / 2; ia >= 0; ia--)
            for(int ib = n / 2; ib >= 0; ib--)
            for(int ic = min(n - ia - ib, n / 2); ic >= 0; ic--){
                if(ia) dp[ia][ib][ic] = max(dp[ia][ib][ic], dp[ia - 1][ib][ic] + a[i]);
                if(ib) dp[ia][ib][ic] = max(dp[ia][ib][ic], dp[ia][ib - 1][ic] + b[i]);
                if(ic) dp[ia][ib][ic] = max(dp[ia][ib][ic], dp[ia][ib][ic - 1] + c[i]);
                res = max(res, dp[ia][ib][ic]);
            }
        cout << res << endl;
    }
    return 0;
}
