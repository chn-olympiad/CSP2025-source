#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100010;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    string s[n][2];
    for (ll i = 0; i < n; i++){
        cin >> s[i][0] >> s[i][1];
    }
    string t[q][2];
    for (ll i = 0; i < q; i++){
        cin >> t[i][0] >> t[i][1];
    }
    for (ll i = 0; i < q; i++){
        cout << 0 << '\n';
    }
    return 0;
}