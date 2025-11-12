#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 7, Mod = 998244353;
ll n, ans, a[N], dp[2][N];
ll cntDp, cntPw, od, nw;

void calc(int m, int lim){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1, cntDp = 0, cntPw = 1;
    od = 0, nw = 1;
    for(int i = 1; i <= m; i++){
        memset(dp[nw],0,sizeof(dp[nw]));
        for(int j = 0; j <= lim; j++){
            (dp[nw][j] += dp[od][j]) %= Mod;
            if(j >= a[i]){
                (dp[nw][j] += dp[od][j-a[i]]) %= Mod;
            }
        }
        swap(od, nw);
    }
    for(int i = 0; i <= lim; i++) (cntDp += dp[od][i]) %= Mod;
    for(int i = 1; i <= m; i++) (cntPw *= 2) %= Mod;
    (ans += (cntPw+Mod-cntDp)%Mod) %= Mod;
    return ;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 3; i <= n; i++){
        calc(i-1, a[i]);
    }
    cout << ans << endl;
    return 0;
}
