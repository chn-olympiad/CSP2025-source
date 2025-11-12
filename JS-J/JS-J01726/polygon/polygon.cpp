#include <bits/stdc++.h>

#define re return
#define ll long long int
#define rep(i, f, t) for(register int i = f; i <= t; ++i)
#define per(i, f, t) for(register int i = f; i >= t; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define con continue
#define gcd __gcd
using namespace std;
int mod = 998244353, n, a[5007], dp[5007]{1}, res, otr;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    rep(i, 1, n)cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n){
        rep(j, a[i] + 1, a[n])res = (res + dp[j]) % mod;
        res = (res + otr) % mod;
        otr = otr * 2 % mod;
        rep(j, a[n] - a[i] + 1, a[n])otr = (otr + dp[j]) % mod;
        per(j, a[n], a[i])dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
    cout << res;
    re 0;
}















/*

Alan-Turing-bao3-wo3-shang4-an4
\o/ \o/ \o/ \o/ \o/ \o/

mi-ma-elbow-cool-ice
:D :D :D :D :D :D

('v')
('-')
('o')
~(-v-)~
(>v<)

\==--\
|=========--<=   WXJQSYSYXX
/==--/

*/

/*
Record my second time to CSP
3:00 go to sleep (-_-)zzz
6:25 wake up (> ~ <)
6:40 have breakfast :P
7:00 leave the hotel ('o')
7:18 reach NMSL(?) NanJingWaiGuoYu ('O')
7:30 get to the classroom ('~')
8:30 start \p.q/ <shui hai you duo yu zi jin>
9:50 accept all the given examples :D
10:20 finish testing them again and have a picnic :P
10:30 go to sleep (-_-)zzz
10:40 wake up again and decide to write a record ('v')
10:50 <del>i don't know because it's 10:46 right now</del>
      add some emoji to this article
*/
