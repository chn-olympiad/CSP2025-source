#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, ans = 0; cin >> n >> m;
    string s; cin >> s;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> id(n + 1), b(n + 1); iota(id.begin(), id.end(), 0);
    
    do {
        for (int i = 1; i <= n; i++) b[i] = a[id[i]];
        ll cnt = 0, sum = 0;
        // for (int i = 1; i <= n; i++) cerr << id[i] << ' ';
        // cerr << endl;
        for (int i = 1; i <= n; i++) {
            if (b[i] <= cnt) {cnt++; continue;}
            if (s[i - 1] == '0') cnt++;
            else if (s[i - 1] == '1') sum++;
        }
        if (sum >= m) ans++;
    } while(next_permutation(id.begin() + 1, id.end()));

    cout << ans;
    return 0;
}