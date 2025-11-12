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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int m, n, a, b, res = 1;
    cin >> n >> m >> a;
    rep(i, 1, m * n - 1)cin >> b, res += (a < b);
    int h = (res - 1) / n + 1;
    cout << h << ' ';
    if(h & 1)cout << (res - 1) % n + 1;
    else cout << n - (res - 1) % n;
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
