#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int p = 131, N = 2e5 + 5, M = 5e6 + 5; ull hsh1[N], hsh2[N], base[M], hsht1[M], hsht2[M]; int n, q, sz[N], loc[N];
int main() {
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        string s1, s2; cin >> s1 >> s2;
        sz[i] = s1.size();
        for(int j = 0; j < sz[i]; j++) hsh1[i] = hsh1[i] * p + s1[j];
        for(int j = 0; j < sz[i]; j++) hsh2[i] = hsh2[i] * p + s2[j];
        for(int j = 0; j < sz[i]; j++) if(s1[j] == 'b') loc[i] = j;
        sum += sz[i];
    }
    base[0] = 1; for(int i = 1; i <= M - 5; i++) base[i] = base[i-1] * p;
    while(q--) {
        string t1, t2; cin >> t1 >> t2;
        if(t1.size() != t2.size()){ cout << 0 << '\n'; continue ; }
        int len = t1.size();
        for(int i = 1; i <= len; i++) hsht1[i] = hsht1[i-1] * p + t1[i-1];
        for(int i = 1; i <= len; i++) hsht2[i] = hsht2[i-1] * p + t2[i-1];
        int ans = 0;
        if(sum <= 2000) {
            for(int i = 1; i <= len; i++) {
                for(int j = 1; j <= n; j++) {
                    int m = sz[j]; if(i + m - 1 > len) continue ;
                    int l = i, r = i + m - 1;
                    if(hsht1[r] - hsht1[l-1] * base[r-l+1] != hsh1[j]) continue ;
                    ull nw = hsht1[l-1] * base[len-l+1] + base[len-r] * hsh2[j] + (hsht1[len] - hsht1[r] * base[len-r]);
                    if(nw == hsht2[len]) ans++;
                }
            }
        }
        else {
            int idx = 0;
            for(int i = 1; i <= len; i++) if(t1[i-1] == 'b') { idx = i; break; }
            for(int i = 1; i <= n; i++) {
                int l = idx - loc[i], r = l + sz[i] - 1;
                if(l < 0 || r > len) continue ;
                if(hsht1[r] - hsht1[l-1] * base[r-l+1] != hsh1[i]) continue ;
                ull nw = hsht1[l-1] * base[len-l+1] + base[len-r] * hsh2[i] + (hsht1[len] - hsht1[r] * base[len-r]);
                if(nw == hsht2[len]) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}