#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1956285342;
int ha[1005], hb[1005], cd[1005];
int hc[1000005], hd;
int n, q;
int pow2(int a, int b) {
    int mul = 1;
    while(b) {
        if(b % 2) {
            mul *= a;
            mul %= mod;
        }
        a *= a;
        b /= 2;
    }
    return mul;
}
int qh(int i, int j) {
    if(i > j) return 0;
    return hc[j] - hc[i - 1] * pow2(27, j - i + 1);
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        cd[i] = a.size();
        for (int j = 0; j < a.size(); ++j) {
            ha[i] *= 27;
            ha[i] += a[j] - 'a' + 1;
            ha[i] %= mod;
            hb[i] *= 27;
            hb[i] += b[j] - 'a' + 1;
            hb[i] %= mod;
        }
 //       cout << ha[i] << " " << hb[i] << "\n";
    }
    while(q--) {
        string c, d;
        cin >> c >> d;
        if(c.size() != d.size()) {
            cout << "0\n";
            continue;
        }
        c = " " + c;
        d = " " + d;
        for (int i = 1; i < c.size(); ++i) {
            hc[i] = hc[i - 1] * 27 + c[i] - 'a' + 1;
            hc[i] %= mod;
            hd = hd * 27 + d[i] - 'a' + 1;
            hd %= mod;
        }
        int cnt = 0;
        for (int i = 1; i < c.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i - cd[j] + 1 >= 1) {
//                    cout << i << " " << j << " " << cd[j] << " " << qh(i - cd[j] + 1, i) << " " << ha[j] << "\n";
                    if(qh(i - cd[j] + 1, i) != ha[j]) continue;
                    if((hc[i - cd[j]] * pow2(27, c.size() - 1 - i + cd[j]) % mod + hb[j] * pow2(27, c.size() - 1 - i) % mod + qh(i + 1, c.size() - 1) % mod) % mod == hd) ++cnt;
 //                   cout << i << " " << j << " " << (hc[i - cd[j]] * pow2(27, c.size() - 1 - i + cd[j] - 1) % mod + hb[j] * pow2(27, c.size() - 1 - i) % mod + qh(i + 1, c.size() - 1) % mod) % mod << "\n";
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}