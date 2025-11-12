#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int MAXLEN = 5.2e6 + 5;
const int HMOD = 998244353;
const int HBAS = 131;
typedef long long ll;

namespace ACAM {

    // huh? CSP-S? ACAM?
    int nd, nxt[27][MAXLEN], fail[MAXLEN], cnt[MAXLEN];

    inline int ord(char ch) { return ch == '#' ? 26 : ch - 'a'; }

    inline void insert(int rt, char * str) {
        if (str[0]) {
            int & p = nxt[ord(str[0])][rt];
            if (p == 0) p = ++ nd;
            insert(p, str + 1);
        } else cnt[rt] ++;
    }

    inline void build(int rt) {
        static queue<int> Q; fail[rt] = rt;
        for (int id = 0; id <= 26; id ++) {
            int & p = nxt[id][rt];
            if (p == 0) p = rt;
            else fail[p] = rt, Q.push(p);
        } while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            cnt[u] += cnt[fail[u]];
            for (int id = 0; id <= 26; id ++) {
                int & p = nxt[id][u];
                if (p == 0) p = nxt[id][fail[u]];
                else fail[p] = nxt[id][fail[u]], Q.push(p);
            }
        }
    }

    inline ll query(int rt, char * str) {
        ll res = 0;
        while (str[0]) {
            rt = nxt[ord(str[0])][rt];
            str ++; res += cnt[rt];
        } return res;
    }

} map<pair<int, int>, int> ACrt;

int n, q; char s1[MAXLEN], s2[MAXLEN], sfin[MAXLEN];

inline pair<int, int> chg(char * s1, char * s2) {
    int len = strlen(s1), l2 = strlen(s2);
    if (len != l2) return {-1, -1};
    int pf = 0; for (; pf < len && s1[pf] == s2[pf]; pf ++);
    if (pf == len) {
        for (int i = 0; i < pf; i ++) sfin[i] = s1[i];
        return {0, 0};
    } int sf = len - 1; for (; s1[sf] == s2[sf]; sf --);
    int ptr = 0; for (int i = 0; i < pf; i ++) sfin[ptr ++] = s1[i];
    sfin[ptr ++] = '#'; for (int i = sf + 1; i < len; i ++) sfin[ptr ++] = s1[i];
    sfin[ptr ++] = '\0'; ll hsh1 = 0, hsh2 = 0;
    for (int i = pf; i <= sf; i ++) hsh1 = (hsh1 * HBAS + s1[i]) % HMOD;
    for (int i = pf; i <= sf; i ++) hsh2 = (hsh2 * HBAS + s2[i]) % HMOD;
    return {hsh1, hsh2};
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> s1 >> s2; pair<int, int> hsh = chg(s1, s2);
        if (ACrt[hsh] == 0) ACrt[hsh] = ++ ACAM :: nd;
        ACAM :: insert(ACrt[hsh], sfin);
    } for (pair<pair<int, int>, int> piii : ACrt)
        ACAM :: build(piii.second);
    for (int i = 1; i <= q; i ++) {
        cin >> s1 >> s2; pair<int, int> hsh = chg(s1, s2);
        if (hsh.first == -1) { cout << 0 << '\n'; continue; }
        if (ACrt[hsh] == 0) { cout << 0 << '\n'; continue; }
        cout << ACAM :: query(ACrt[hsh], sfin) << '\n';
    } return 0;
}
