#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string s1[N], s2[N];
using ull = unsigned long long;
ull lis[5] = {2593, 4283, 8369, 5407, 7243};
mt19937 rd(time(0));
ull B;
struct HSH {
    vector<ull> h, b;
    int n;
    HSH(int _n, string s) : n(_n) {
        h.assign(n + 1, 0);
        b.assign(n + 1, 0);
        b[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * B + s[i];
            b[i] = b[i - 1] * B;
        }
    }
    ull H(int l, int r) {
        return h[r] - h[l - 1] * b[r - l + 1];
    }
};
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    B = lis[rd() % 5];
    int n, q;
    cin >> n >> q;
    int l1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        l1 += s1[i].size();
    } 
    if (l1 <= 2000) {
        vector<pair<ull, ull>> lis;
        for (int i = 1; i <= n; i++) {
            ull h1 = 0, h2 = 0;
            for (auto x : s1[i]) h1 = h1 * B + x;
            for (auto x : s2[i]) h2 = h2 * B + x;
            lis.push_back({h1, h2});
        }
        sort(lis.begin(), lis.end());
        while (q--) {
            string t1, t2;
            cin >> t1 >> t2;
            int n = t1.size();
            t1 = ' ' + t1, t2 = ' ' + t2;
            HSH h1(n, t1), h2(n, t2);
            int pl = 1, pr = n;
            for (int i = 1; i <= n; i++) {
                if (t1[i] == t2[i]) pl = i + 1;
                else break;
            }
            for (int i = n; i >= 1; i-- ){
                if (t1[i] == t2[i]) pr = i - 1;
                else break;
            }
            ull ans = 0;
            for (int i = pl; i >= 1; i--) {
                for (int j = pr; j <= n; j++) {
                    auto cur = make_pair(h1.H(i, j), h2.H(i, j));
                    ans += upper_bound(lis.begin(), lis.end(), cur) - lower_bound(lis.begin(), lis.end(), cur);
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }
    vector<pair<pair<ull, ull>, ull>> lis;
    for (int i = 1; i <= n; i++) {
        int m = s1[i].size();
        s1[i] = ' ' + s1[i];
        s2[i] = ' ' + s2[i];
        int pos;
        for (int j = 1; j <= m;j++) {
            if (s1[i][j] == 'b' || s2[i][j] == 'b') pos = j;
        }
        ull h1 = 0, h2 = 0;
        for (int j = 1; j <= pos; j++) {
            h1 = h1 * B + s1[i][j];
            h2 = h2 * B + s2[i][j];
        }
        lis.push_back({{h1, h2}, m - pos});
        for (int j = pos + 1; j <= m; j++) {
            h1 = h1 * B + s1[i][j];
            h2 = h2 * B + s2[i][j];
            lis.push_back({{h1, h2}, m - j});
        }
    }
    sort(lis.begin(), lis.end());
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int n = t1.size();
        t1 = ' ' + t1, t2 = ' ' + t2;
        HSH h1(n, t1), h2(n, t2);
        int pl = 1, pr = n;
        for (int i = 1; i <= n; i++) {
            if (t1[i] == t2[i]) pl = i + 1;
            else break;
        }
        for (int i = n; i >= 1; i-- ){
            if (t1[i] == t2[i]) pr = i - 1;
            else break;
        }
        ull ans = 0;
        for (int i = pl; i >= 1; i--) {
            auto cur = make_pair(make_pair(h1.H(i, pr), h2.H(i, pr)), (ull)n - pr);
            ans += upper_bound(lis.begin(), lis.end(), cur) - lower_bound(lis.begin(), lis.end(), make_pair(cur.first, 0ull));
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
4 2
xabcx
xadex
ab
cd
bc
de
aa bb
xabcx
xadex
*/