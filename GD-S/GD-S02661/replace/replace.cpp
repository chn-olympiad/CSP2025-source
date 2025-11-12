#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 200005, L = 5000005;
int n, q;
int cnt[26], pos[N][2];
unsigned long long hshs[N][2], p[L], hsh1[L], hsh2[L];
string s[N][2];
bool flag = 1;
map <int, int> mp;
unsigned long long gethsh(string s) {
    int n = s.size();
    unsigned long long res = 0;
    for (int i = 0; i < n; i++) res = res * 131 + s[i];
    return res;
}
unsigned long long gethsh1(int l, int r) { 
    if (l > r) return 0;
    return hsh1[r] - hsh1[l - 1] * p[r - l + 1]; 
}
unsigned long long gethsh2(int l, int r) { 
    if (l > r) return 0;
    return hsh2[r] - hsh2[l - 1] * p[r - l + 1]; 
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        for (char c : s[i][0]) cnt[c - 'a']++;
        hshs[i][0] = gethsh(s[i][0]), hshs[i][1] = gethsh(s[i][1]);
    }
    if (!cnt[0] or cnt[1] != 1) flag = 0;
    for (int i = 2; i < 26; i++) { if (cnt[i]) flag = 0; }
    if (flag) {
        for (int i = 1; i <= n; i++) {
            int pos1 = 0, pos2 = 0, len = s[i][0].size();
            for (int j = 0; j < len; j++) {
                if (s[i][0][j] == 'b') pos1 = j + 1;
                if (s[i][1][j] == 'b') pos1 = j + 1;
            }
            mp[pos1 - pos2]++;
        }
        while (q--) {
            int pos1 = 0, pos2 = 0, len;
            string t1, t2; cin >> t1 >> t2;
            if (t1.size() != t2.size()) { cout << "0\n"; continue; }
            for (int i = 0; i < len; i++) {
                if (t1[i] == 'b') pos1 = i + 1;
                if (t2[i] == 'b') pos2 = i + 1;
            }
            cout << mp[pos1 - pos2] << '\n';
        }
    }
    else {
        while (q--) {
            ll len, ans = 0;
            string t1, t2; cin >> t1 >> t2;
            if (t1.size() != t2.size()) { cout << "0\n"; continue; }
            len = t1.size(), p[0] = 1;
            for (int i = 0; i < len; i++) {
                hsh1[i + 1] = hsh1[i] * 131 + t1[i];
                hsh2[i + 1] = hsh2[i] * 131 + t2[i];
                p[i + 1] = p[i] * 131;
            }
            for (int i = 1; i <= n; i++) {
                int tmp = s[i][0].size(); 
                for (int j = 1; j + tmp - 1 <= len; j++) {
                    if (gethsh1(j, j + tmp - 1) == hshs[i][0] and gethsh2(j, j + tmp - 1) == hshs[i][1] and gethsh1(1, j - 1) == gethsh2(1, j - 1) and gethsh1(j + tmp, len) == gethsh2(j + tmp, len)) ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}