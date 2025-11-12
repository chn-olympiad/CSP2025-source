#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
#ifndef LOCAL
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
#endif
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<array<string, 2>> s(n + 1);
    vector<int> len(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        len[i] = (int)s[i][0].size();
    }

    for(int i = 1; i <= q; i++) {
        string x, y;
        cin >> x >> y;
        int m = (int)x.size(), ans = 0;
        for(int j = 1; j <= n; j++) {
            if(len[j] > m) {
                continue;
            }
            for(int k = 0; k + len[j] <= m; k++) {
                if(x.substr(k, len[j]) == s[j][0]) {
                    string z = x.substr(0, k) + s[j][1] + x.substr(k + len[j]);
                    if(z == y) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}