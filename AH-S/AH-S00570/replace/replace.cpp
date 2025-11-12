#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
map <string, int> mp;
const int N = 5e6 + 10;
#define ull unsigned long long
const ull base = 82613;
ull w[N];
struct node {
    string s1, s2;
    int l, r, len, bh;
    bool operator < (const node &W) const {
        return len < W.len;
    }
} s[N], t[N];
ull hsh1[N], hsh2[N], hsh1a[N], hsh2a[N];
ull th1[N], th2[N];
int sum = 0;
int ans[N];
ull gin(string s) {
    ull res = 0;
    for (int i = 0; i < s.size(); i ++) res = res * base + s[i] - 'a';
    return res;
}
ull gin2(string s, int l, int r) {
    ull res = 0;
    for (int i = l; i <= r; i ++) res = res * base + s[i] - 'a';
    return res;
}
ull solve(int ver, int l, int r) {
    if(ver == 1) {
        return th1[r] - th1[l - 1] * w[r - l + 1];
    }
    else {
        return th2[r] - th2[l - 1] * w[r - l + 1];
    }
}
signed main(void) {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    w[0] = 1;
    for (int i = 1; i <= N - 10; i ++) w[i] = w[i - 1] * base;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i].s1 >> s[i].s2;
        int l = 0, r = s[i].s1.size() - 1;
        while (s[i].s1[l] == s[i].s2[l]) l ++;
        while (s[i].s1[r] == s[i].s2[r]) r --;
        s[i].l = l, s[i].r = r;
        s[i].len = r - l + 1;
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i ++) {
        int l = s[i].l, r = s[i].r;
        hsh1[i] = gin2(s[i].s1, l, r);
        hsh2[i] = gin2(s[i].s2, l, r);
        hsh1a[i] = gin(s[i].s1);
        hsh2a[i] = gin(s[i].s2);
    }
    int nq = 0;
    for (int i = 1; i <= q; i ++) {
        string t1, t2;
        cin >> t1 >> t2;
        if(t1.size() != t2.size()) {
            ans[i] = 0;
            continue ;
        }
        nq ++;
        t[nq].s1 = t1, t[nq].s2 = t2;
        int l = 0, r = t[nq].s1.size() - 1;
        while (t[nq].s1[l] == t[nq].s2[l]) l ++;
        while (t[nq].s1[r] == t[nq].s2[r]) r --;
        t[nq].l = l, t[nq].r = r;
        t[nq].len = r - l + 1;
        t[nq].bh = i;
        if(t1 == t2) {
            for (int j = 1; j <= n; j ++) {
                ans[i] += (t1.find(s[j].s1) != string :: npos && s[j].s1 == s[j].s2);
            }
        }
    }
    int gq = q;
    q = nq;
    sort(t + 1, t + q + 1);
    int now = 1;
    for (int i = 1; i <= q; i ++) {
        string t1, t2;
        t1 = t[i].s1, t2 = t[i].s2;
        for (int j = 0; j < t1.size(); j ++) th1[j] = th1[j - 1] * base + t1[j] - 'a';
        for (int j = 0; j < t2.size(); j ++) th2[j] = th2[j - 1] * base + t2[j] - 'a';
        int l = t[i].l, r = t[i].r, len = t[i].len;
        while (now <= n && s[now].len != t[i].len) now ++;
        //cout << now << endl;
        if(now > n) {
            break ;
        }
        ull h1, h2;
        int res = 0;
        h1 = solve(1, l, r), h2 = solve(2, l, r);
        for (int j = now; s[j].len == len; j ++) {
            //cout << h1 << ' ' << h2 << endl;
            if(h1 != hsh1[j] || h2 != hsh2[j]) continue ;
            int sl = s[j].l, sr = s[j].r;
            int fs = l - sl, fe = r + (s[j].s1.size() - sr) - 1;
            //cout << fs << ' ' << fe << endl;
            if(fs < 0 || fe >= t1.size()) {
                continue ;
            }
            ull all1 = solve(1, fs, fe), all2 = solve(2, fs, fe);
            //cout << all1 << ' ' << all2 << endl;
            //cout << hsh1a[j] << ' ' << hsh2a[j] << endl;
            if(all1 == hsh1a[j] && all2 == hsh2a[j]) res ++;
        }
        //res = res;
        ans[t[i].bh] = res;
    }
    for (int i = 1; i <= gq; i ++) cout << ans[i] << endl;
    return 0;
}
