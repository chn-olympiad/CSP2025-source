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
int cnt[20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(char c : s)if(c >= '0' && c <= '9')cnt[c- '0']++;
    per(i, 9, 0)rep(j, 1, cnt[i])cout << i;
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
