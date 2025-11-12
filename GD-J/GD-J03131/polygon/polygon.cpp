#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define gc getchar()
using namespace std;

int rd()
{
    int x = 0, f = 1;
    char c = gc;
    for(; !isdigit(c); c = gc) if(c == '-') f = -1;
    for(; isdigit(c); c = gc) x = x * 10 + (c ^ 48);
    return x * f;
}

int MOD(int x){while(x >= mod) x = x - mod;return x;}

int n, ans, qpow = 1;
int a[5005], dp[2][5005];

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = rd();
    for(int i = 1; i <= n; i++) a[i] = rd();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        ans = MOD(ans + qpow - i + mod);
        for(int j = 0; j <= a[i]; j++) ans = MOD(ans - dp[1][j] + mod);
        for(int j = 5004; j >= a[i]; j--)
            dp[1][j] = MOD(dp[1][j] + dp[0][j - a[i]] + dp[1][j - a[i]]);
        dp[0][a[i]]++;
        qpow = qpow * 2 % mod;
    }
    cout << ans << "\n";
    return 0;
}
// 祝me, fish酱, ylx, cz, lws, ljq, zfz, xyq, wgk, shy, zy, hsy, wcx AK
// 游记:
// 0-30min 玩虚拟机，打快读 T1
// 30-35min T2
// 35-45min 推 T3
// 45-60min T3 n^2 做法
// 60-90min 想到用set维护，n log n
// 90-140min 上厕所+T4n^2做法
// 140min-150min 游记
// 150min-170min 对拍 
// 一堆人排队上厕所eee 
// 220min-230min 对拍答案算错，把自己吓得半死 
