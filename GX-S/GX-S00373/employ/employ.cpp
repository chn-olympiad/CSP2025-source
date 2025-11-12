#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
int c[105];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m; cin >> n >> m;
    string s; cin >> s;

    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    vector<int> q;
    for (int i = 1; i <= n; i ++) q.push_back(i);
    int ans = 0;
    do {
        int nopass = 0;
        int cntpass = 0;
        for (int i = 0; i < q.size(); i ++) {
            // if (s[i] == '0' || nopass >= c[i]) nopass ++;
            // else cntpass ++;
            if (s[i] == '1' && nopass < c[i]) cntpass ++;
            else nopass ++;
        }
        if (cntpass >= m) ans ++;
        ans = ans % mod;
    }while (!next_permutation(q.begin(), q.end()));
    
    cout << ans << '\n';
    return 0;
}