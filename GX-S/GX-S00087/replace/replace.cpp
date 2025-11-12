#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 2e5 + 1;
string aa[MAXN], bb[MAXN], qa, qb;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    ull n, q, ans, wh;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> aa[i] >> bb[i];
    }
    string tmp;
    for (int i = 1; i <= q; i++) {
        cin >> qa >> qb;
        if (qa.size() != qb.size()) {
            cout << "0\n";
            continue;
        }
        ans = 0;
        for (int i = 1; i<=n; i++) {
            for (int j = 0; (wh = qa.find(aa[i], j)) != string::npos; j = wh+1) {
                tmp = qa;
                for (int k = 0; k < aa[i].size(); k++) {
                    tmp[wh + k] = bb[i][k];
                }
                if (tmp == qb) ans++;
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}