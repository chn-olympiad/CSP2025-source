#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

const int N = 5000010, B = 31;
int n, q;
u64 pw[N];
vector<string> s[2], t[2];
vector<vector<u64>> hs[2], ht[2];

void calc(vector<u64>& h, const string& s) {
    h.resize(s.size());
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++) h[i] = h[i - 1] * B + s[i] - 'a' + 1;
}

u64 get_hash(const vector<u64>& h, int l, int r) {
    if (l == 0) return h[r];
    return h[r] - h[l - 1] * pw[r - l + 1];
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * B;
    cin >> n >> q;
    for (int i = 0; i < 2; i++) {
        s[i].resize(n + 5);
        t[i].resize(n + 5);
        hs[i].resize(n + 5);
        ht[i].resize(n + 5);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[0][i] >> s[1][i];
        calc(hs[0][i], s[0][i]);
        calc(hs[1][i], s[1][i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[0][i] >> t[1][i];
        calc(ht[0][i], t[0][i]);
        calc(ht[1][i], t[1][i]);
    }
    for (int i = 1; i <= q; i++) {
        int l = 0, r = t[0][i].length() - 1, w = r - l + 1;
        while (t[0][i][l] == t[1][i][l]) l++;
        while (t[0][i][r] == t[1][i][r]) r--;
        u64 h0 = get_hash(hs[0][i], l, r);
        u64 h1 = get_hash(hs[1][i], l, r);
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k + w <= s[0][j].length(); k++) {
                int p1 = l - k, p2 = r + s[0][j].length() - k - w + 1;
                // fprintf(stderr, "p1 = %d p2 = %d\n", p1, p2);
                // fprintf(stderr, "len = %d\n", s[0][j].length() - 1);
                // assert(p2 - p1 == s[0][j].length() - 1);
                if (p1 < 0) continue;
                if (p2 >= t[0][i].length()) continue;
                if (get_hash(hs[0][j], 0, w - 1) == h0 && get_hash(hs[0][j], 0, s[0][j].length() - 1) == get_hash(hs[0][i], p1, p2) && get_hash(hs[1][j], 0, s[1][j].length() - 1) == get_hash(hs[1][i], p1, p2)) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}