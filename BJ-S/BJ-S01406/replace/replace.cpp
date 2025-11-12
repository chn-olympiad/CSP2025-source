#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -f;
        } 
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
#define rd read()
using ull = unsigned long long;

const int N = 2e3 + 10;
int n, q;
const int P = 131;
ull hs[N][2][N], ht[2][N];
ull p[N];
string s[N][2];

ull Hash(ull h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = rd, q = rd;
    p[0] = 1;
    for (int i = 1; i <= 1e3; i++) {
        p[i] = p[i - 1] * P;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
        s[i][1] = " " + s[i][1], s[i][2] = " " + s[i][2];
        for (int j = 1; j < s[i][1].size(); j++) {
            hs[i][1][j] = hs[i][1][j - 1] * P + s[i][1][j];
            hs[i][2][j] = hs[i][2][j - 1] * P + s[i][2][j];
        }
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int cnt = 0;
        if (t1.size() != t2.size()) {
            cout << cnt << endl;
            continue ;
        }
        ht[1][0] = ht[2][0] = 0;
        t1 = " " + t1, t2 = " " + t2;
        for (int i = 1; i < t1.size(); i++) {
            ht[1][i] = ht[1][i - 1] * P + t1[i];
            ht[2][i] = ht[2][i - 1] * P + t2[i];
        }
        for (int i = 1; i < t1.size(); i++) {
            for (int j = 1; j <= n; j++) {
                if (i + s[j][1].size() - 2 >= t1.size()) {
                    continue ;
                }
                int sz = s[j][1].size();
                if (Hash(ht[1], i, i + sz - 2) == Hash(hs[j][1], 1, sz - 1)
                &&  Hash(ht[2], i, i + sz - 2) == Hash(hs[j][2], 1, sz - 1)
                &&  (i + sz - 1 >= t1.size() || Hash(ht[1], i + sz - 1, t1.size() - 1) == Hash(ht[2], i + sz - 1, t2.size() - 1))) {
                    cnt++;
                    // cerr << i << ' ' << j << endl;
                }
            }
            if (t1[i] != t2[i]) {
                break ;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}