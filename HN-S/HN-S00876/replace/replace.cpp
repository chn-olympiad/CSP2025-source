#include <bits/stdc++.h>
#define int long long
#define ui64 unsigned long long
#define Pii pair<int, int>
#define Sc second
#define Fr first
#define ls(x) x << 1
#define rs(x) x << | 1

using namespace std;

const int kMaxN = 5e6 + 5, Mod = 998244353, Base = 223;

ui64 a[2][kMaxN];
ui64 f[2][kMaxN], pw[kMaxN];
int n, q;
string ss1[kMaxN], ss2[kMaxN], tt1[kMaxN], tt2[kMaxN];

int l[kMaxN], r[kMaxN], tot;
map<int, int> mp;
vector<int> G[kMaxN];

ui64 C(string s) {
    ui64 ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret = ret * Base + s[i];
    }
    return ret;
}

ui64 P(int op, int l, int r) {
    return f[op][r] - f[op][l - 1] * pw[(r - l + 1)];
}

void Solve1() {
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * Base;
    for (int i = 1; i <= n; i++) {
        string s1 = ss1[i], s2 = ss2[i];
        l[i] = s1.size();
        a[0][i] = C(s1), a[1][i] = C(s2);
    }
    for (int fu = 1; fu <= q; fu++) {
        string t1 = tt1[fu], t2 = tt2[fu];
        int m = t1.size();
        t1 = " " + t1, t2 = " " + t2;
        for (int i = 1; i <= m; i++) {
            f[0][i] = f[0][i - 1] * Base + t1[i];
            f[1][i] = f[1][i - 1] * Base + t2[i];
        }
        int ans = 0, L = 0, R = m + 1;
        for (int i = 1; i <= m; i++) {
            L = i;
            if (t1[i] != t2[i]) break;
        }
        for (int i = m; i >= 1; i--) {
            R = i;
            if (t1[i] != t2[i]) break;
        }
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= n; j++) {
                if (i + l[j] - 1 <= m && i + l[j] - 1 >= R) {
                    ui64 x = P(0, i, i + l[j] - 1), y = P(1, i, i + l[j] - 1);
                    if (x == a[0][j] && y == a[1][j]) {
                        ans++; 
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}

void Solve2() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1 = ss1[i], s2 = ss2[i];
        int L = s1.size(); s1 = " " + s1, s2 = " " + s2;
        int x = 0, y = 0;
        for (int i = 1; i <= L; i++) {
            if (s1[i] == 'b') {
                x = i; break;
            }
        }
        l[i] = x - 1;
        for (int i = 1; i <= L; i++) {
            if (s2[i] == 'b') {
                y = i; break;
            }
        }
        r[i] = L - y;
        int t = x - y;
        if (mp[t] == 0) mp[t] = ++tot;
        t = mp[t];
        G[t].push_back(i);
    }
    for (int fu = 1; fu <= q; fu++) {
        string s1 = tt1[fu], s2 = tt2[fu];
        int L = s1.size(); s1 = " " + s1, s2 = " " + s2;
        int x = 0, y = 0;
        for (int i = 1; i <= L; i++) {
            if (s1[i] == 'b') {
                x = i; break;
            }
        }
        int ll = x - 1;
        for (int i = 1; i <= L; i++) {
            if (s2[i] == 'b') {
                y = i; break;
            }
        }
        int rr = L - y;
        int t = x - y;
        int ans = 0;
        t = mp[t];
        if (t == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (auto v : G[t]) {
            if (l[v] <= ll && rr >= r[v]) ans++;
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios:: sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    bool flag1 = 1;
    for (int i = 1; i <= n; i++) {
        cin >> ss1[i] >> ss2[i];
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < ss1[i].size(); j++) cnt0 += ss1[i][j] == 'b', cnt1 += ss2[i][j] == 'b';
        if (cnt0 != 1 || cnt1 != 1) flag1 = 0;
    }
    for (int i = 1; i <= q; i++) {
        cin >> tt1[i] >> tt2[i];
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < tt1[i].size(); j++) cnt0 += tt1[i][j] == 'b', cnt1 += tt2[i][j] == 'b';
        if (cnt0 != 1 || cnt1 != 1) flag1 = 0;
    }
    if (flag1 == 0) {
        Solve1();
    } else {
        Solve2();
    }
    return 0;
}