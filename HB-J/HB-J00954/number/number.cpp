#include <bits/stdc++.h>
// #define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (int)(b) ; i++)
#define rloop(i, a, b) for(int i = (b) ; i >= (int)(a) ; i--)
#define chkmin(a, b) (a = min(a, b))
#define chkmax(a, b) (a = max(a, b))
using namespace std;
string a, b;
void solve() {
    cin >> a;
    for(auto c : a) if(isdigit(c)) b += c;
    sort(b.begin(), b.end(), greater<>());
    cout << b << '\n';
}
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
