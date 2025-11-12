#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int N = 510;
const ll p = 998244353;

int n, m;
int c[N], s[N];
ll comb[N][N], fac[N];

namespace verybf {
    int p[N];
    int main () {
        for (int i = 1; i <= n; i ++) p[i] = i;
        int cnt = 0;
        do {
            int giveup = 0, cnt1 = 0;
            for (int i = 1; i <= n; i ++) {
                if (s[i] == 1 && giveup < c[p[i]]) ++ cnt1; 
                else giveup ++;
            }
            if (cnt1 >= m) cnt ++;
        } while (next_permutation (p + 1, p + n + 1));
        printf ("%d\n", cnt);
        return 0;
    }
}

namespace feaB {
    vector <int> truepos;
    struct BIT {
        int t[N], n;
        void init (int x) { n = x + 5; for (int i = 1; i <= n; i ++) t[i] = 0; }
        int lb (const int x) { return x & -x; }
        void add (int x, int k) { x ++; for (; x <= n; x += lb (x)) t[x] += k; }
        int qry (int x) { x ++; int ret = 0; for (; x > 0; x -= lb (x)) ret += t[x]; return ret; }
        int qry (int l, int r) { return qry (r) - qry (l - 1); }
    } bit;

    int buc[N];
    
int main () {
    int C = 0;
    for (int i = 1; i <= n; i ++)
        if (s[i]) truepos.push_back (i), ++ C;
    reverse (truepos.begin (), truepos.end ());
    int U = 1 << C;

    fprintf (stderr, "cnt = %d\n", C);

    ll ans = 0;
    for (int msk = 0; msk < U; msk ++) {
        bit.init (n);
        for (int i = 1; i <= n; i ++) bit.add (c[i], 1);

        int cnt = 0, www;
        for (int i = 0; i < C; i ++) cnt += (msk >> i & 1);
        if (cnt < m) continue;
        www = cnt; // ok persons
        fprintf (stderr, "msk = %d is ok and now cnt = %d\n", msk, cnt);

        ll res = 1;
        for (const auto& pos : truepos) {
            if (cnt > 0 && (msk >> cnt - 1)& 1) -- cnt;
            int giveup = pos - cnt - 1;
            if (msk >> cnt & 1) {
                ll prd = bit.qry (giveup + 1, n);
                fprintf (stderr, "prod = %lld [giveup = %d]\n", prd, giveup);
                res = res * bit.qry (giveup + 1, n) % p;
                bit.add (giveup + 1, -1);
            } else {
                res = res * bit.qry (1, giveup) % p;
                bit.add (1, -1);
            }
        }
        ans = (ans + res * fac[n - www]) % p;
    }

    printf ("%lld\n", ans);
    return 0;
}
}

int main (void) {

    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);

    int up = 500;
    for (int i = 0; i <= up; i ++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            comb[i][j] = (comb[i - 1][j] + comb[i][j - 1]) % p;
    }
    fac[0] = 1;
    for (int i = 1; i <= up; i ++) fac[i] = fac[i - 1] * i % p;

    scanf ("%d%d", &n, &m); int cnt = 0;
    for (int i = 1; i <= n; i ++) scanf ("%1d", s + i), cnt += s[i];
    for (int i = 1; i <= n; i ++) scanf ("%d", c + i);
    // fprintf (stderr, "cnt = %d\n", cnt);
    // if (cnt <= 18) return feaB :: main ();
    if (n <= 10) return verybf :: main ();

    return 0;
}