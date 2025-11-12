#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5 + 5, L = 5e6 + 5;
const ULL B = 13331;

int n, q, lens[N], lent;
string s[N][2], t[2];
ULL p[L], hs[N][2];
vector<ULL> ht[2];

namespace Code1 {
    ULL get(vector<ULL> &h, int l, int r) {
        if (l > r) return 0;
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    void solve() {
        p[0] = 1;
        for (int i = 1; i < L; i++) {
            p[i] = p[i - 1] * B;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < lens[i]; k++) {
                    hs[i][j] = hs[i][j] * B + (s[i][j][k] - 'a' + 1);
                }
            }
        }
        while (q--) {
            cin >> t[0] >> t[1];
            if (t[0].size() != t[1].size()) {
                cout << 0 << '\n';
                continue;
            }
            lent = t[1].size();
            for (int i = 0; i < 2; i++) {
                ht[i].assign(lent + 1, 0);
                for (int j = 0; j < lent; j++) {
                    ht[i][j + 1] = ht[i][j] * B + (t[i][j] - 'a' + 1);
                }
            }
            LL ans = 0;
            for (int i = 1; i <= lent; i++) {
                for (int j = 1; j <= n; j++) {
                    if (lens[j] > i) continue;
                    if (ht[0][i - lens[j]] == ht[1][i - lens[j]]) {
                        if (get(ht[0], i + 1, lent) == get(ht[1], i + 1, lent)) {
                            if (hs[j][0] == get(ht[0], i - lens[j] + 1, i)) {
                                if (hs[j][1] == get(ht[1], i - lens[j] + 1, i)) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> s[i][j];
            lens[i] = s[i][j].size();
        }
    }

    Code1::solve();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    solve();
    return 0;
}