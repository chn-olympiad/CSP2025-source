#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define PHH pair<HASH, HASH>

const int LEN = 5e6 + 5, N = 2e5 + 5;
const int mod1 = 292042171, mod2 = 492598261, BASE1 = 131, BASE2 = 1181;

int pw[LEN][2];

struct HASH {
    PII pr;
    int len;

    bool operator < (const HASH &b) const {
        return pr < b.pr;
    }
    bool operator == (const HASH &b) const {
        return pr == b.pr;
    }
    bool operator != (const HASH &b) const {
        return pr != b.pr;
    }
    HASH operator + (const HASH &b) {
        HASH res;

        res.len = len + b.len;
        res.pr.fi = (1ll * pr.fi * pw[len][0] % mod1 + b.pr.fi) % mod1;
        res.pr.se = (1ll * pr.se * pw[len][1] % mod2 + b.pr.se) % mod2;

        return res;
    }
    HASH operator - (const HASH &b) {
        HASH res;

        res.len = len - b.len;
        res.pr.fi = (pr.fi - b.pr.fi * pw[len - b.len][0] % mod1 + mod1) % mod1;
        res.pr.se = (pr.se - b.pr.se * pw[len - b.len][1] % mod2 + mod2) % mod2;

        return res;
    }

    void init(int n, char *s) {
        pr.fi = pr.se = 0;
        len = n;

        for(int i = 1; i <= len; i++) {
            pr.fi = (1ll * pr.fi * BASE1 % mod1 + s[i] - 'a' + 1) % mod1;
            pr.se = (1ll * pr.se * BASE2 % mod2 + s[i] - 'a' + 1) % mod2;
        }
    }
    void insert(int pos, char c) {
        len++;
        if(pos == 0) {
            pr.fi = (1ll * pr.fi * BASE1 % mod1 + c - 'a' + 1) % mod1;
            pr.se = (1ll * pr.se * BASE2 % mod2 + c - 'a' + 1) % mod2;
        } else {
            pr.fi = (pr.fi + 1ll * pw[pos][0] * (c - 'a' + 1) % mod1) % mod1;
            pr.se = (pr.se + 1ll * pw[pos][1] * (c - 'a' + 1) % mod2) % mod2;
        }
    }
};

int n, q, l[N], len[N], cnt;
char s[LEN], t[LEN], tmp[LEN];
HASH pre[LEN][2];
PHH trans[N];
map<PHH, int> pos;
vector<int> endlen[N];

HASH getHash(char *ss, int l, int r) {
    for(int i = l; i <= r; i++) {
        tmp[i - l + 1] = ss[i];
    }

    HASH res;

    res.init(r - l + 1, tmp);

    return res;
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> q;

    pw[0][0] = pw[0][1] = 1;
    for(int i = 1; i <= 5000000; i++) {
        pw[i][0] = 1ll * pw[i - 1][0] * BASE1 % mod1;
        pw[i][1] = 1ll * pw[i - 1][1] * BASE2 % mod2;
    }

    for(int i = 1; i <= n; i++) {
        cin >> (s + 1);
        cin >> (t + 1);

        int st = 114514191, ed = 0;
        len[i] = strlen(s + 1);

        for(int j = 1; j <= len[i]; j++) {
            if(s[j] != t[j]) {
                st = min(st, j);
                ed = j;
            }
        }

        if(st > ed) {
            n--;
            i--;
            continue;
        }

        l[i] = st;
        trans[i] = MP(getHash(s, 1, len[i]), getHash(t, 1, len[i]));

        PHH pre = MP(getHash(s, 1, ed), getHash(t, 1, ed));

        if(pos[pre] == 0) {
            pos[pre] = ++cnt;
        }
            endlen[pos[pre]].push_back(n - ed);

        // HASH ssub1 = getHash(s, 1, st - 1), ssub2 = getHash(s, st, ed), ssub3 = getHash(s, ed + 1, len);
        // HASH tsub1 = getHash(t, 1, st - 1), tsub2 = getHash(t, st, ed), tsub3 = getHash(t, ed + 1, len);

        // cnt[0][MP(ssub1, tsub1)]++;
        // cnt[1][MP(ssub2, tsub2)]++;
        // cnt[2][MP(ssub3, tsub3)]++;
        // cnt[3][MP(ssub1 + ssub2, tsub1 + tsub2)]++;
        // cnt[4][MP(ssub1 + ssub3, tsub1 + tsub3)]++;
        // cnt[5][MP(ssub2 + ssub3, tsub2 + tsub3)]++;
    }

    for(int i = 1; i <= cnt; i++) {
        sort(endlen[i].begin(), endlen[i].end());
    }

    if(1ll * n * q > 100000000) {
        while(q--) {
            cin >> (s + 1);
            cin >> (t + 1);

            int st = 114514191, ed = 0, ln = strlen(s + 1);

            if(ln != (int)strlen(t + 1)) {
                cout << "0\n";
                continue;
            }
            
            for(int i = 1; i <= ln; i++) {
                if(s[i] != t[i]) {
                    st = min(st, i);
                    ed = i;
                }
            }

            PHH dif = MP(getHash(s, st, ed), getHash(t, st, ed));
            int ans = 0;

            for(int i = st; i; i--) {
                int p = pos[dif];

                if(p != 0) {
                    ans += upper_bound(endlen[p].begin(), endlen[p].end(), ln - ed) - endlen[p].begin();
                }

                dif.fi.insert(ed - i, s[i]);
                dif.se.insert(ed - i, t[i]);
            }

            cout << ans << '\n';
        }
    } else {
        while(q--) {
            cin >> (s + 1);
            cin >> (t + 1);

            int st = 114514191, ed = 0, ln = strlen(s + 1);

            if(ln != (int)strlen(t + 1)) {
                cout << "0\n";
                continue;
            }
            
            for(int i = 1; i <= ln; i++) {
                if(s[i] != t[i]) {
                    st = min(st, i);
                    ed = i;
                }
            }

            HASH cur;

            cur.pr.fi = cur.pr.se = cur.len = 0;

            for(int i = 1; i <= ln; i++) {
                cur.insert(0, s[i]);
                pre[i][0] = cur;
            }

            cur.pr.fi = cur.pr.se = cur.len = 0;

            for(int i = 1; i <= ln; i++) {
                cur.insert(0, t[i]);
                pre[i][1] = cur;
            }

            int ans = 0;

            for(int i = 1; i <= n; i++) {
                int pos = st - l[i] + 1;

                if(pos < 1 || pos + len[i] - 1 < ed || pos + len[i] - 1 > ln) {
                    continue;
                }

                if(trans[i] == MP(pre[pos + len[i] - 1][0] - pre[pos - 1][0], pre[pos + len[i] - 1][1] - pre[pos - 1][1])) {
                    ans++;
                }
            }

            cout << ans << '\n';

            // int ans = n;
            // HASH ssub1 = getHash(s, 1, st - 1), ssub2 = getHash(s, st, ed), ssub3 = getHash(s, ed + 1, len);
            // HASH tsub1 = getHash(t, 1, st - 1), tsub2 = getHash(t, st, ed), tsub3 = getHash(t, ed + 1, len);

            // ans -= cnt[0][MP(ssub1, tsub1)];
            // ans -= cnt[1][MP(ssub2, tsub2)];
            // ans -= cnt[2][MP(ssub3, tsub3)];
            // ans += cnt[3][MP(ssub1 + ssub2, tsub1 + tsub2)];
            // ans += cnt[4][MP(ssub1 + ssub3, tsub1 + tsub3)];
            // ans += cnt[5][MP(ssub2 + ssub3, tsub2 + tsub3)];

            // cout << ans << '\n';
        }
    }
}
/*
3 1
ca cb
a b
dad dbd
cac cbc
*/