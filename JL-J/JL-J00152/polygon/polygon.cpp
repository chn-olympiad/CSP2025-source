#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10,mod = 998244353;
int n;
int a[N];
int dp[3][N * 2][5];
int ans;

int qpow(int x,int y){
    int res = 1,base = x;
    while(y){
        if(y & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        y >>= 1;
    }
    return (res - 1 + mod) % mod;
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n +1);
    dp[0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 10000;j >= 0;j--){
            dp[i & 1][j][0] = dp[i & 1][j][1] = 0;
            if(a[i] <= j) dp[i & 1][j][1] = (dp[(i - 1) & 1][j - a[i]][1] + dp[(i - 1) & 1][j - a[i]][0]) % mod;
            dp[i & 1][j][0] = (dp[(i - 1) & 1][j][1] + dp[(i - 1) & 1][j][0]) % mod;
            if(j <= a[i] * 2) ans = (dp[i & 1][j][1] + ans) % mod;
        }
    }
    cout<<(qpow(2,n) - ans + mod) % mod;
}
