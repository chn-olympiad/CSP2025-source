#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int N = 2e5 + 5;

array<int, 8> hs[N];

int32_t main() {
    ifstream cin("replace.in");
    ofstream cout("replace.out");
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    if (n * q <= 2e7) {
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 == s2) {
                hs[i] = {-1, 0, 0, 0, 0, 0, 0, 0}; // hs[i][0] = -1 -> invalid
                continue;
            }
            int sz = s1.length(), l = 0, r = sz - 1;
            while (s1[l] == s2[l]) l++;
            while (s1[r] == s2[r]) r--;
            // [l ... r] = b
            int cur = 0, bs = 1;
            hs[i][0] = l;
            for (int j = l - 1; j >= 0; j--) {
                cur = (cur + (s1[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            hs[i][1] = cur;
            hs[i][2] = hs[i][4] = r - l + 1;
            cur = 0, bs = 1;
            for (int j = l; j <= r; j++) {
                cur = (cur + (s1[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            hs[i][3] = cur;
            cur = 0, bs = 1;
            for (int j = l; j <= r; j++) {
                cur = (cur + (s2[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            hs[i][5] = cur;
            cur = 0, bs = 1;
            hs[i][6] = sz - r - 1;
            for (int j = r + 1; j < sz; j++) {
                cur = (cur + (s1[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            hs[i][7] = cur;
        }
        while (q--) {
            string t1, t2;
            cin >> t1 >> t2;
            if (t1.length() != t2.length()) {
                cout << 0 << "\n";
                continue;
            }
            int sz = t1.length(), l = 0, r = sz - 1;
            while (t1[l] == t2[l]) l++;
            while (t1[r] == t2[r]) r--;
            // [l ... r] = b
            int cur = 0, bs = 1, hsb1, hsb2;
            // hs[i][0] = l;
            int hsa[l + 1], hsc[sz - r];
            
            for (int j = l - 1; j >= 0; j--) {
                cur = (cur + (t1[j] - 'a' + 1) * bs) % MOD;
                hsa[l - 1 - j] = cur;
                bs = bs * 67 % MOD;
            }
            // hs[i][1] = cur;
            // hs[i][2] = hs[i][4] = r - l + 1;
            hsb1 = 0, bs = 1;
            for (int j = l; j <= r; j++) {
                hsb1 = (hsb1 + (t1[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            // hs[i][3] = cur;
            hsb2 = 0, bs = 1;
            for (int j = l; j <= r; j++) {
                hsb2 = (hsb2 + (t2[j] - 'a' + 1) * bs) % MOD;
                bs = bs * 67 % MOD;
            }
            // hs[i][5] = cur;
            cur = 0, bs = 1;
            // hs[i][6] = sz - r - 1;
            for (int j = r + 1; j < sz; j++) {
                cur = (cur + (t1[j] - 'a' + 1) * bs) % MOD;
                hsc[j - r - 1] = cur;
                bs = bs * 67 % MOD;
            }
            // hs[i][7] = cur;

            int ans = 0;
            for (int j = 0; j < n; j++) {
                if (hs[j][0] == -1) continue;
                if (r - l + 1 != hs[j][2] || hsb1 != hs[j][3] || hsb2 != hs[j][5]) continue;
                if (l < hs[j][0] || sz - r - 1 < hs[j][6]) continue;
                if (hs[j][0] > 0 && hsa[hs[j][0] - 1] != hs[j][1]) continue;
                if (hs[j][6] > 0 && hsc[hs[j][6] - 1] != hs[j][7]) continue;
                ans++;
            }
            cout << ans << "\n";
        }
    }
    else {
        vector<array<int, 4>> vec;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 == s2) continue;
            int sz = s1.length(), l = 0, r = sz - 1;
            while (s1[l] == s2[l]) l++;
            while (s1[r] == s2[r]) r--;
            vec.emplace_back((array<int, 4>) {r - l + 1, (s1[l] == 'b'), l, sz - r - 1});
        }
        sort(vec.begin(), vec.end());
        while (q--) {
            string t1, t2;
            cin >> t1 >> t2;
            if (t1.length() != t2.length()) {
                cout << 0 << "\n";
                continue;
            }
            int sz = t1.length(), l = 0, r = sz - 1;
            while (t1[l] == t2[l]) l++;
            while (t1[r] == t2[r]) r--;
            int bl = r - l + 1, bt = (t1[l] == 'b'), al = l, cl = sz - r - 1;
            int ans = 0;
            for (int i = 0; i <= al; i++) {
                int lb = lower_bound(vec.begin(), vec.end(), (array<int, 4>) {bl, bt, i, 0}) - vec.begin();
                int ub = upper_bound(vec.begin(), vec.end(), (array<int, 4>) {bl, bt, i, cl}) - vec.begin();
                ans += max(0LL, ub - lb);
            }
            cout << ans << "\n";
        }
    }
}