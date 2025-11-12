#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
const long long mod = 1000000009ll * 998244853ll;
struct ACTrie {
    int ch[5000010][27];
    int ed[5000010], fail[5000010];
    int tot;
    int new_node() {
        ++tot;
        for (int i = 0; i <= 26; i++) {
            ch[tot][i] = 0;
        }
        fail[tot] = ed[tot] = 0;
        return tot;
    }
    void init() {
        tot = 0;
    }
    void insert(int root, string s) {
        int p = root;
        for (int i = 0; i < (int)s.size(); i++) {
            int id = s[i] - 'a';
            if (s[i] == '#') {
                id = 26;
            }
            if (ch[p][id] == 0) {
                ch[p][id] = ++tot;
            }
            p = ch[p][id];
        }
        ++ed[p];
    }
    queue<int> q;
    void build(int root) {
        while (!q.empty()) {
            q.pop();
        }
        fail[root] = root;
        for (int i = 0; i <= 26; i++) {
            if (ch[root][i]) {
                fail[ch[root][i]] = root;
                q.push(ch[root][i]);
            } else {
                ch[root][i] = root;
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            ed[t] += ed[fail[t]];
            for (int i = 0; i <= 26; i++) {
                if (ch[t][i]) {
                    fail[ch[t][i]] = ch[fail[t]][i];
                    q.push(ch[t][i]);
                } else {
                    ch[t][i] = ch[fail[t]][i];
                }
            }
        }
    }
} act;
int n, q;
string s[200010][2], t[200010][2];
map<__int128, int> mp;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        if (s[i][0] == s[i][1]) {
            continue;
        }
        int l = s[i][0].size();
        int minpos = 1e9, maxpos = -1e9;
        for (int j = 0; j < l; j++) {
            if (s[i][0][j] != s[i][1][j]) {
                minpos = min(minpos, j);
                maxpos = max(maxpos, j);
            }
        }
        __int128 H = 1;
        for (int j = minpos; j <= maxpos; j++) {
            H = (31 * H + s[i][0][j] - 'a') % mod;
        }
        for (int j = minpos; j <= maxpos; j++) {
            H = (31 * H + s[i][1][j] - 'a') % mod;
        }
        if (!mp.count(H)) {
            mp[H] = act.new_node();
        }
        int rt = mp[H];
        string now = "";
        for (int j = 0; j < l; j++) {
            if (j == minpos) {
                j = maxpos;
                now += '#';
            } else {
                now += s[i][0][j];
            }
        }
        act.insert(rt, now);
    }
    for (auto i : mp) {
        act.build(i.second);
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i][0] >> t[i][1];
        if (t[i][0].size() != t[i][1].size()) {
            printf("0\n");
            continue;
        }
        int l = t[i][0].size();
        int minpos = 1e9, maxpos = -1e9;
        for (int j = 0; j < l; j++) {
            if (t[i][0][j] != t[i][1][j]) {
                minpos = min(minpos, j);
                maxpos = max(maxpos, j);
            }
        }
        __int128 H = 1;
        for (int j = minpos; j <= maxpos; j++) {
            H = (31 * H + t[i][0][j] - 'a') % mod;
        }
        for (int j = minpos; j <= maxpos; j++) {
            H = (31 * H + t[i][1][j] - 'a') % mod;
        }
        if (!mp.count(H)) {
            printf("0\n");
            continue;
        }
        int rt = mp[H];
        long long ans = 0;
        for (int j = 0; j < l; j++) {
            if (j == minpos) {
                j = maxpos;
                rt = act.ch[rt][26];
                ans += act.ed[rt];
            } else {
                rt = act.ch[rt][t[i][0][j] - 'a'];
                ans += act.ed[rt];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
