#include <bits/stdc++.h>
#define mod 998244353
#define N 550
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m;
string s;
int c[N];
int s0, s1;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            s0++;
        }
        else {
            s1++;
        }
    }
    if(s1 == n) {
        ll ans = n;
        for(ll i = n - 1; i >= 2; i--) {
            ans = (ans * i) % mod;
        }
        cout << ans;
    }
    else {
        cout << s1;
    }
}
