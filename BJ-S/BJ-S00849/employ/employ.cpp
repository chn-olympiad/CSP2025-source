#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m,dp[505][505][505],a[505],p,p2,ans;
string c;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>c;
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    dp[0][0][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            for(int k = 0 ; k <= n - j; k++){
                for(int q = 1 ; q <= n ; q++){
                if(a[q] < j+1)continue;
                if(a[q] == j+1){
                    if(p2 == 0)p2 = q-1;
                    continue;
                }
                p = q-1;
                break;
                }
                if(n - j - k - p > 0 && k > 1)dp[i][j][k] += dp[i-1][j][k-1];
                if(p2 > 0 && j > 0)dp[i][j][k] += dp[i-1][j-1][k];
                dp[i][j][k] %= mod;
            }
        }
    }
    for(int i = m ; i <= n ; i++){
        ans += dp[n][n-i][i];
    }
    cout<<ans;
    return 0;
}