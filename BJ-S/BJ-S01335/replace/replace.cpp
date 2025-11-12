#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long mod = 1e9 + 77, base = 31, md = 998244353;
const int N = 2e5 + 5;
struct node {
    string s1, s2;
} a[N];
int n, q;
long long hs1[N], hs2[N], ths1[N], ths2[N], tmd[N];
int hss1(int l, int r) {
    return ((ths1[r] + mod - (ths1[l - 1] * tmd[r - l + 1] % mod)) % mod + mod) % mod;
}
int hss2(int l, int r) {
    return ((ths2[r] + mod - (ths2[l - 1] * tmd[r - l + 1] % mod)) % mod + mod) % mod;
}
namespace sub1 {
    void solve() {
        for(int i = 1; i <= n; i++) {
            string t1 = a[i].s1, t2 = a[i].s2;
            long long tp1 = 0, tp2 = 0;
            for(int j = 0; j < t1.size(); j++) {
                tp1 = (tp1 * base % mod + (int)(t1[j] - 'a')) % mod;
                tp2 = (tp2 * base % mod + (int)(t2[j] - 'a')) % mod;
            }
            hs1[i] = tp1, hs2[i] = tp2;
        }
        tmd[0] = 1;
        for(int i = 1; i <= 200000; i++) tmd[i] = (tmd[i - 1] * base) % mod;
        while(q--) {
            string t1, t2;
            cin >> t1 >> t2;
            t1 = " " + t1;
            t2 = " " + t2;
            int k = 0;
            int mx = 0, mn = t1.size();
            for(int i = 1; i < t1.size(); i++) {
                if(t1[i] != t2[i]) {
                    mn = i;
                    break;
                }
            }
            for(int i = t1.size() - 1; i >= 1; i--) {
                if(t1[i] != t2[i]) {
                    mx = i;
                    break;
                }
            }
            for(int i = 1; i < t1.size(); i++) ths1[i] = (ths1[i - 1] * base % mod + (int)(t1[i] - 'a')) % mod;
            for(int i = 1; i < t2.size(); i++) ths2[i] = (ths2[i - 1] * base % mod + (int)(t2[i] - 'a')) % mod;
            long long ans = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j + a[i].s1.size() - 1 < t1.size(); j++) {
                    //cout << j << " " << j + a[i].s1.size() - 1 << "\n";
                    //cout << "hs1:" << hs1[i] << " " << "hss1:" << hss1(j, j + a[i].s1.size() - 1) << "\n";
                    if(hs1[i] == hss1(j, j + a[i].s1.size() - 1) && hs2[i] == hss2(j, j + a[i].s1.size() - 1) && j <= mn && j + a[i].s1.size() - 1 >= mx) ans++, ans %= md;
                }
            }
            cout << ans << "\n";
        }
    }
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i].s1 >> a[i].s2;
    if(n <= 1000 && q <= 1000) sub1 :: solve();
    else {
        while(q--) cout << "0\n";
    }
    return 0;
}
