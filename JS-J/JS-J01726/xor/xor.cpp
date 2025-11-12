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
int n, k, a, res, x;
set<int> s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k, s.insert(0);
    rep(i, 1, n){
        cin >> a, x ^= a;
        if(s.count(x ^ k))res++, s.clear();
        s.insert(x);
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
