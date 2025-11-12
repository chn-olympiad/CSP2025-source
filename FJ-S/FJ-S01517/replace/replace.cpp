#include <bits/stdc++.h>

using std::cin;
using std::cout;
using u64 = unsigned long long;

const int N = 200020, L = 5000050, B = 2347;

u64 pw[L], h1[L], h2[L], lh1[N], lh2[N], rh1[N], rh2[N];
int n, q;
int l[N], r[N];
std::map<std::pair<u64, u64>, std::vector<int>> mp;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < L; i++) pw[i] = pw[i - 1] * B;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::string s1, s2;
        cin >> s1 >> s2;
        for (int j = 0; j < s1.length() && s1[j] == s2[j]; j++) l[i]++;
        for (int j = s1.length() - 1; ~j && s1[j] == s2[j]; j--) r[i]++;
        if (l[i] < s1.length()) {
            for (int j = 0; j < l[i]; j++) {
                lh1[i] = lh1[i] * B + s1[j];
                lh2[i] = lh2[i] * B + s2[j];
            }
            for (int j = s1.length() - r[i]; j < s1.length(); j++) {
                rh1[i] = rh1[i] * B + s1[j];
                rh2[i] = rh2[i] * B + s2[j];
            }
            u64 val1 = 0, val2 = 0;
            for (int j = l[i]; j < s1.length() - r[i]; j++) {
                val1 = val1 * B + s1[j];
                val2 = val2 * B + s2[j];
            }
            mp[{val1, val2}].emplace_back(i);
        }
    }
    for (std::string t1, t2; q--; ) {
        cin >> t1 >> t2;
        int m = t1.length();
        t1 = " " + t1, t2 = " " + t2;
        for (int i = 1; i <= m; i++) {
            h1[i] = h1[i - 1] * B + t1[i];
            h2[i] = h2[i - 1] * B + t2[i];
        }
        int tl = 0, tr = 0;
        for (int i = 1; i <= m && t1[i] == t2[i]; i++) tl++;
        for (int i = m; i && t1[i] == t2[i]; i--) tr++;
        u64 val1 = 0, val2 = 0;
        for (int i = tl + 1; i <= m - tr; i++) {
            val1 = val1 * B + t1[i];
            val2 = val2 * B + t2[i];
        }
        if (!mp.count({val1, val2})) {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for (int i : mp[{val1, val2}]) if (tl >= l[i] && tr >= r[i]) {
            int tmp = h1[tl] - pw[l[i]] * h1[tl - l[i]] == lh1[i];
            tmp &= h2[tl] - pw[l[i]] * h2[tl - l[i]] == lh2[i];
            tmp &= h1[m - tr + r[i]] - pw[r[i]] * h1[m - tr] == rh1[i];
            tmp &= h2[m - tr + r[i]] - pw[r[i]] * h2[m - tr] == rh2[i];
            ans += tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}