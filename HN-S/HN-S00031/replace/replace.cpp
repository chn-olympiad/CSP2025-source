#include<bits/stdc++.h>
#define int long long
using ull = unsigned long long;
using namespace std;
constexpr int N = 5e6 + 5;
constexpr ull base = 1145141;
int n, q, L[N];
ull p[N], hs1[N], hs2[N], h1[N], h2[N];
inline ull query1(int l, int r) {
    return hs1[r] - hs1[l - 1] * p[r - l + 1];
}
inline ull query2(int l, int r) {
    return hs2[r] - hs2[l - 1] * p[r - l + 1];
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        L[i] = s1.size();
        s1 = ' ' + s1, s2 = ' ' + s2;
        for(int j = 1; j <= L[i]; j++) {
            h1[i] = h1[i] * base + s1[j];
            h2[i] = h2[i] * base + s2[j];
        }
    }
    while(q--) {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.size();
        s1 = ' ' + s1, s2 = ' ' + s2;
        p[0] = 1;
        for(int i = 1; i <= m; i++) {
            hs1[i] = hs1[i - 1] * base + s1[i];
            hs2[i] = hs2[i - 1] * base + s2[i];
            p[i] = p[i - 1] * base;
        }
        int l = 1, r = m;
        while(l <= m && s1[l] == s2[l]) l++;
        while(r && s1[r] == s2[r]) r--;
        if(s1[l] == s2[l]) l++;
        if(s1[r] == s2[r]) r--;
        int ans = 0;
        for(int i = 1; i <= l; i++) {
            for(int j = 1; j <= n; j++) {
                if(i + L[j] - 1 < r || i + L[j] - 1 > m) continue;
                if(h1[j] == query1(i, i + L[j] - 1) && h2[j] == query2(i, i + L[j] - 1)) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}