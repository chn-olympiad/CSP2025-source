#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 200005;
int curr_max, n, q;
string s1, s2;

ull h1[N], h2[N], len[N];

ull hs[5000005], hs2[5000005];


ull pw[5000005];

void makehs(string s, string t) {
    for(int i = 1; i <= s1.size(); i++) {
        hs[i] = hs[i - 1] * 29;
        hs[i] += (s[i - 1] - 'a' + 1);
    }
    for(int i = 1; i <= s2.size(); i++) {
        hs2[i] = hs2[i - 1] * 29;
        hs2[i] += (t[i - 1] - 'a' + 1);
    }
}

ull gethash(string s) {
    ull r = 0;
    for(int i = 0; i < s.size(); i++) {
        r *= 29; r += (s[i] - 'a' + 1);
    }
    return r;
}

ull seghash(int l, int r, int k) {
    if(k == 1) return hs[r] - hs[l - 1] * pw[r - l + 1];
    else return hs2[r] - hs2[l - 1] * pw[r - l + 1];
}


int match(int i, int sz) {
    int ret = 0;
    int sublen = len[i];
    for(int l = 1; l + sublen - 1 <= sz; l++) {
        bool ok = true;
        if(seghash(l, l + sublen - 1, 1) != h1[i] || seghash(l, l + sublen - 1, 2) != h2[i]) ok = false;
        if(l > 1 && seghash(1, l - 1, 1) != seghash(1, l - 1, 2)) ok = false;
        if(l + sublen - 1 < n && seghash(l + sublen, n, 1) != seghash(l + sublen, n, 2)) ok = false;
        if(ok) ret++;
    }
    return ret;
}


int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pw[0] = 1;
    for(int i = 1; i <= 5000005; i++) pw[i] = pw[i - 1] * 29;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        len[i] = s1.size(), h1[i] = gethash(s1), h2[i] = gethash(s2);
    }
    while(q--) {
        cin >> s1 >> s2;
        int ans = 0;
        makehs(s1, s2);
        for(int i = 1; i <= n; i++) {
            ans += match(i, s1.size());
        }
        cout << ans << endl;

    }
    return 0;

}
