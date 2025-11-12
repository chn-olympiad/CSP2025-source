/*
META:
BJ-S00702 2025/11/1
replace.cpp T3
Status=Give up,Locked
Guess Score=10
E1 AC
E2 AC
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, q;
string from[200005], to[200005];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> from[i] >> to[i];
    while (q--) {
        string a, b;
        cin >> a >> b;
        int ans = 0;
        int l = a.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + from[i].size() - 1 < l; j++) {
                if (a.substr(j, from[i].size()) == from[i]) {
                    string fn = a.substr(0, j), af = a.substr(j + from[i].size());
                    if (fn + to[i] + af == b) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
