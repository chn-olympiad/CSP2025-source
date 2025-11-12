// 09:58 AC this problem
// I think I'm AK now
// There are 1:56 there, after test in Linux, make a small game?

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define MOD 998244353ll
using namespace std;

int n;
int num[5005];
int dp[5005][5005];

int qpow(int a,int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    int tmp = qpow(a,x>>1);
    if(x & 1) return tmp*tmp % MOD*a % MOD;
    else return tmp*tmp % MOD;
}

signed main() 
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> num[i];
    sort(num+1,num+n+1);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=5000;j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= num[i]) dp[i][j] += dp[i-1][j-num[i]];
            dp[i][j] %= MOD;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5000;j++)
            dp[i][j] = (dp[i][j]+dp[i][j-1]) % MOD;
    int ans = 0;
    for(int i=3;i<=n;i++) {
        ans += qpow(2,i-1);
        ans -= dp[i-1][num[i]];
        ans = (ans+MOD) % MOD;
    } cout << ans;
    return 0;
}

/***
 * Key words:
 *
 * #include <bits\stdc++.h>
 * int mian()
 * froepen
 * freopen("polygon.in ","r",stdin);
 * freopen("polygon.out","r",stdout);
 * int x0,y0,x1,y1;
 *
 * CCF
 * // freopen("polygon.in","r",stdin);
 * // freopen("polygon.out","w",stdout);
 *
 * freopen("polygon4.in","r",stdin);
 * freopen("polygon.ans","w",stdout);
 *
 * sto sto sto orz orz orz
 * sto sto sto orz orz orz
 * void Slove() {}
*/