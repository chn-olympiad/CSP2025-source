#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ull unsigned long long

const int N = 2e5 + 5, base = 1e9 + 7, L = 5e6 + 5;
int n, Q, sz[N];
string s1, s2;
ull has[N][2], p[L];
ull h[L], h2;

ull query (int l, int r) {
    if (l > r) return 0;
    return h[r] - h[l - 1] * p[r - l + 1];
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> Q;
    p[0] = 1;
    for (int i = 1; i < L; ++i)
        p[i] = p[i - 1] * base;
    for (int i = 1; i <= n; ++i) {
        cin >> s1 >> s2;
        int l = s1.size();
        s1 = " " + s1, s2 = " " + s2;
        for (int j = 1; j <= l; ++j)
            has[i][0] = (has[i][0] * base + s1[j]);
        for (int j = 1; j <= l; ++j)
            has[i][1] = (has[i][1] * base + s2[j]);
        sz[i] = l;
        //cout << sz[i] << ' ' << has[i][0] << ' ' << has[i][1] << '\n';
    }
    while (Q --) {
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            cout << "0\n";
            continue ;
        }
        int l = s1.size();
        s1 = " " + s1, s2 = " " + s2;
        for (int i = 1; i <= l; ++i)
            h[i] = h[i - 1] * base + s1[i];
        h2 = 0;
        for (int i = 1; i <= l; ++i)
            h2 = h2 * base + s2[i];
        /*
        for (int i = 1; i <= l; ++i)
            cout << h[i] << ' ';
        cout << '\n';
        cout << h2 << "\n\n";
        */
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j + sz[i] - 1 <= l; ++j) {
                if (query(j, j + sz[i] - 1) == has[i][0]) {
                    //cout << j << ' ' << j + sz[i] - 1 << '\n';
                    ull to = h[l] - has[i][0] * p[j - 1] + has[i][1] * p[j - 1];
                    if (to == h2) ++ ans/*, cout << "haha!\n"*/;
                }
            }
        }
        cout << /*'\n' << */ans << '\n';
    }
    return 0;
}
