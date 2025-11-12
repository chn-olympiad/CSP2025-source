#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, tct, tr[570005][676], ed[2500005], ln[2500005], lt[2500005], fa[2500005][22], sz[2500005][22];
string s[200005][2], t[200005][2];
bool fg;

namespace Sub1 {
    
int tr[2500005][4];

int main() {
    for (int i = 1; i <= n; i++) {
        int p(0);
        for (int j = 0; j < s[i][0].length(); j++) {
            int x = (s[i][0][j] - 'a') * 2 + s[i][1][j] - 'a';
            if (!tr[p][x]) tr[p][x] = ++tct, ln[tct] = ln[p] + 1;
            p = tr[p][x];
            // cout << i << ' ' << s[i][0][j] << ' ' << s[i][1][j] << ' ' << p << '\n';
        }
        ed[p]++;
    }
    // cerr << tct << '\n';
    queue<int> q;
    for (int i = 0; i < 4; i++) if (tr[0][i]) q.push(tr[0][i]);
    while (q.size()) {
        int x = q.front(); q.pop();
        fa[x][0] = lt[x];
        sz[x][0] = ed[lt[x]];
        // cout << x << ' ' << lt[x] << '\n';
        for (int i = 1; i < 22; i++) {
            fa[x][i] = fa[fa[x][i - 1]][i - 1];
            sz[x][i] = sz[x][i - 1] + sz[fa[x][i - 1]][i - 1];
        }
        for (int i = 0; i < 4; i++) {
            if (tr[x][i]) {
                q.push(tr[x][i]);
                lt[tr[x][i]] = tr[lt[x]][i];
            } else {
                tr[x][i] = tr[lt[x]][i];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i][0] >> t[i][1];
        int st(-1), tt(-1);
        for (int j = 0; j < t[i][0].length(); j++) {
            if (t[i][0][j] != t[i][1][j]) {
                if (!~st) st = j;
                tt = j;
            }
        }
        int p(0), rs(0);
        for (int j = 0; j < t[i][0].length(); j++) {
            int x = (t[i][0][j] - 'a') * 2 + t[i][1][j] - 'a';
            p = tr[p][x];
            if (j >= tt) {
                int lth(j - st + 1), pp(p);
                if (ln[pp] >= lth) {
                    rs += ed[pp];
                    for (int k = 21; k >= 0; k--) {
                        if (ln[fa[pp][k]] >= lth) rs += sz[pp][k], pp = fa[pp][k];
                    }
                }
            }
        }
        cout << rs << '\n';
    }
    return 0;
}

}

signed main() {
#ifdef LARRIX
    freopen("replace3.in", "r", stdin);
    freopen("sample.out", "w", stdout);
#else
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        for (int j = 0; j < s[i][0].length(); j++) {
            if (s[i][0][j] > 'b' || s[i][1][j] > 'b') fg = 1;
        }
    }
    if (!fg) return Sub1::main();
    for (int i = 1; i <= n; i++) {
        int p(0);
        for (int j = 0; j < s[i][0].length(); j++) {
            int x = (s[i][0][j] - 'a') * 26 + s[i][1][j] - 'a';
            if (!tr[p][x]) tr[p][x] = ++tct, ln[tct] = ln[p] + 1;
            p = tr[p][x];
        }
        ed[p]++;
    }
    queue<int> q;
    for (int i = 0; i < 676; i++) if (tr[0][i]) q.push(tr[0][i]);
    while (q.size()) {
        int x = q.front(); q.pop();
        fa[x][0] = lt[x];
        sz[x][0] = ed[lt[x]];
        for (int i = 1; i < 22; i++) {
            fa[x][i] = fa[fa[x][i - 1]][i - 1];
            sz[x][i] = sz[x][i - 1] + sz[fa[x][i - 1]][i - 1];
        }
        for (int i = 0; i < 676; i++) {
            if (tr[x][i]) {
                q.push(tr[x][i]);
                lt[tr[x][i]] = tr[lt[x]][i];
            } else {
                tr[x][i] = tr[lt[x]][i];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i][0] >> t[i][1];
        int st(-1), tt(-1);
        for (int j = 0; j < t[i][0].length(); j++) {
            if (t[i][0][j] != t[i][1][j]) {
                if (!~st) st = j;
                tt = j;
            }
        }
        int p(0), rs(0);
        for (int j = 0; j < t[i][0].length(); j++) {
            int x = (t[i][0][j] - 'a') * 26 + t[i][1][j] - 'a';
            p = tr[p][x];
            if (j >= tt) {
                int lth(j - st + 1), pp(p);
                if (ln[pp] >= lth) {
                    rs += ed[pp];
                    for (int k = 21; k >= 0; k--) {
                        if (ln[fa[pp][k]] >= lth) rs += sz[pp][k], pp = fa[pp][k];
                    }
                }
            }
        }
        cout << rs << '\n';
    }
    return 0;
}
/*
g++ -o replace replace.cpp -std=c++14 -O2 -DLARRIX ; if [ $? -eq 0 ]; then /usr/bin/time -f "%es, %MKB" ./replace ; fi
*/
/*
很明显两个串的条件是没用的，直接压成一个串。
从题目来看只能用一次替换，那很明显就是后缀自动机的板题？就是求某个后缀的长度要大于某个值的个数。怎么想都不太可行。不过我也不太会SAM。
我怎么感觉SAM加个倍增就可以了呢？不对好像AC自动机+倍增就行了。靠，要手搓AC自动机了。
考虑用链表模拟 Trie 树。这属于用时间换空间了，感觉要带个 26 倍的时间常数。
相当于不把两个串拼一起，把其中一维放前面。不对，你要AC自动机就一定得用 5e6 * 676 条边的信息。
除非我们打一个错误的AC自动机实现方式，舍弃掉辅助数组，只保留往上跳的数组。这样的话倍增也失去意义了。
这个在全是 a 和 b 的情况下好像会炸吧。我们能否把这种情况特判掉呢？
要不就放弃一切用 map。但是要两倍空间。
*/