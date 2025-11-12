#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int N = 5e6 + 10;
const ll p = 1e9 + 7;
const ll base = 19260817;
const ll p2 = 998244353;
const ll base2 = 13331;

ll qpow (ll base, ll k, ll p) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * base % p;
        base = base * base % p;
        k >>= 1;
    }
    return ret;
}

struct Hash {
    ll val1, val2;
    bool operator == (Hash b) {
        return val1 == b.val1 && val2 == b.val2;
    }
    Hash operator - (Hash b) {
        return {(val1 - b.val1 + p) % p, (p2 + val2 - b.val2) % p2};
    }
};

Hash operator + (Hash a, char ch) {
    ll val1 = (a.val1 * base + ch - 'a' + 1) % p2;
    ll val2 = (a.val2 * base2 + ch - 'a' + 1) % p2;
    return {val1, val2};
}

Hash operator * (Hash a, ll sz) {
    return {a.val1 * qpow (sz, base, p) % p, a.val2 * qpow (sz, base2, p2) % p2};
}

char s1[N], s2[N];
vector < vector <pair <Hash, Hash> > > hsh; 
vector <int> stsz;

Hash getpart (vector <Hash>& pre, int l, int r) {
    return pre[r] - pre[l - 1];
}

Hash connc (Hash a, Hash b, ll sz) {
    Hash aa = a * sz;
    return {(aa.val1 + b.val1) % p, (aa.val2 + b.val2) % p2};
}

int main (void) {

    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);

    int n, q;
    scanf ("%d%d\n", &n, &q); hsh.push_back ({}); stsz.push_back (0);
    for (int i = 1; i <= n; i ++) {
        scanf ("%s %s", s1 + 1, s2 + 1);
        hsh.push_back ({}); int sz = strlen (s1 + 1);
        stsz.push_back (sz);
        hsh.back ().assign (sz + 5, {{0, 0}, {0, 0}});
        for (int j = 1; j <= sz; j ++) 
        hsh[i][j] = {hsh[i][j - 1].first + s1[j], hsh[i][j - 1].second + s2[j]};
    }   

    while (q --) {
        scanf ("%s %s", s1 + 1, s2 + 1);
        vector <Hash> pre; Hash h2 = {0, 0};
        pre.push_back ({0, 0});
        int sz = strlen (s1 + 1);
        if (strlen (s1 + 1) != strlen (s2 + 1)) {
            puts ("0");
            continue;
        }
        for (int i = 1; i <= sz; i ++) {
            pre.push_back ({0, 0});
            pre.back () = pre[i - 1] + s1[i];
            h2 = h2 + s2[i]; 
        }

        ll ans = 0;
        for (int i = 1; i <= sz; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (stsz[j] + i - 1 > sz) continue;
                int nsz = stsz[j];
                if (getpart (pre, i, i + nsz - 1) == hsh[j].back ().first)
                if (connc ( connc (pre[i - 1], hsh[j].back ().second, nsz), getpart (pre, i + nsz, sz), sz - (i + nsz) + 1) == h2)
                    ++ ans;
            } 
        }

        printf ("%lld\n", ans);
    }

    return 0;
}