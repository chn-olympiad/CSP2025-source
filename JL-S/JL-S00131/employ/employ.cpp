#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e2 + 10,mod = 998244353;
int n,m,id;
int a[N];
string s;
int c[N];
int dp[N][N][N];
int ans;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s = " " + s;
    for(int i = 1;i <= n;i++) cin>>c[i];
    int now = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '0') now++;
        else a[++id] = now;
    }
    dp[0][0][0] = 1;
    for(int i = 1;i <= id;i++) dp[i][0][0] = 1;
    for(int i = 1;i <= n;i++) dp[0][i][0] = 1;
    for(int i = 1;i <= id;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 0;k <= i;k++){
                if(c[j] <= a[i]){
                    dp[i][j][k] = (dp[i][j - 1][k] + dp[i - 1][j][k] + dp[i - 1][j - 1][k]) % mod;
                }else{
                    dp[i][j][k] = (dp[i][j - 1][k] + dp[i - 1][j][k]) % mod;
                    if(k != 0) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1]) % mod ;
                }
            }
        }
    }
    for(int i = m;i <= id;i++) ans += dp[id][n][i];
    cout<<ans;
}
