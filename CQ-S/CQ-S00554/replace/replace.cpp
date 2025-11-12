// 意外地好调。但好像 RE 了，Linux 测一下
// 哈希没取模， 666
#include <bits/stdc++.h>
const int base = 131;
const int maxn = 3e6 + 5;
const int mod = 998244353;
int totL, totR, now;
int dfn[maxn], rfn[maxn];
std::vector<std::pair<int, int> > qry[maxn];
std::unordered_map<int, int> TL[maxn], TR[maxn];
std::vector<std::pair<int, std::string> > pos[maxn];
void DFS(int x) {
    dfn[x] = ++now;
    for (auto &[i, j] : TR[x])
        DFS(j);
    rfn[x] = now;
    return;
}
long long bit1[maxn], bit2[maxn], res[maxn];
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
    for (int i = x; i <= now; i += lowbit(i))
        bit1[i] += v, bit2[i] += x * v;
    return;
}
long long ask(int x) {
    auto res = 0ll;
    for (int i = x; i; i -= lowbit(i))
        res += (x + 1) * bit1[i] - bit2[i];
    return res;
}
void DFS1(int x) {
    std::vector<int> pid;
    for (auto &[rt, s] : pos[x]) {
        int p = rt;
        bool flag = false;
        for (auto i : s) {
            if (!TR[p].count(i - 'a')) {
                flag = true;
                break;
            }
            p = TR[p][i - 'a'];
        }
        if (!flag) {
            add(dfn[p], 1);
            add(rfn[p] + 1, -1);
            pid.push_back(p);
        }
    }
    for (auto &[id, p] : qry[x])
        res[id] += ask(dfn[p]) - ask(dfn[p] - 1);
    for (auto [i, j] : TL[x])
        DFS1(j);
    for (auto p : pid)
        add(dfn[p], -1), add(rfn[p] + 1, 1);
    return;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    auto stime = std::chrono::steady_clock::now();
    int n, q;
    std::cin >> n >> q;
    std::string s1, s2;
    std::unordered_map<int, std::unordered_map<int, int> > t;
    auto fun = [&](std::string &s, int l, int r) {
        auto h = 0ll;
        for (int i = l; i <= r; ++i)
            h = (h * base + s[i]) % mod;
        return (int)h;
    };
    int cnt = 0;
    std::vector<int> Lrt, Rrt;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s1 >> s2;
        int L = -1, R = 0;
        for (int j = 0; j < (int)s1.length(); ++j)
            if (s1[j] != s2[j]) {
                R = j;
                if (L == -1)
                    L = j;
            }
        if (L != -1) {
            int h1 = fun(s1, L, R), h2 = fun(s2, L, R);
            if (!t.count(h1) || !t[h1].count(h2)) {
                t[fun(s1, L, R)][fun(s2, L, R)] = cnt++;
                Lrt.push_back(++totL), Rrt.push_back(++totR);
            }
            int pL = Lrt[t[h1][h2]];
            for (int i = L - 1; ~i; --i) {
                if (!TL[pL].count(s1[i] - 'a'))
                    TL[pL][s1[i] - 'a'] = ++totL;
                pL = TL[pL][s1[i] - 'a'];
            }
            pos[pL].emplace_back(Rrt[t[h1][h2]], s1.substr(R + 1, (int)s1.length() - R - 1));
        }
    }
    for (int i = 1; i <= q; ++i) {
        std::cin >> s1 >> s2;
        if ((int)s1.length() != (int)s2.length())
            continue;
        int L = -1, R = 0;
        for (int j = 0; j < (int)s1.length(); ++j)
            if (s1[j] != s2[j]) {
                R = j;
                if (L == -1)
                    L = j;
            }
        int h1 = fun(s1, L, R), h2 = fun(s2, L, R);
        if (!t.count(h1) || !t[h1].count(h2))
            continue;
        int pL = Lrt[t[h1][h2]];
        for (int i = L - 1; ~i; --i) {
            if (!TL[pL].count(s1[i] - 'a'))
                break;
            pL = TL[pL][s1[i] - 'a'];
        }
        int pR = Rrt[t[h1][h2]];
        for (int i = R + 1; i < (int)s1.length(); ++i) {
            if (!TR[pR].count(s1[i] - 'a'))
                TR[pR][s1[i] - 'a'] = ++totR;
            pR = TR[pR][s1[i] - 'a'];
        }
        qry[pL].emplace_back(i, pR);
    }
    for (int i = 0; i < cnt; ++i)
        DFS(Rrt[i]);
    for (int i = 0; i < cnt; ++i)
        DFS1(Lrt[i]);
    for (int i = 1; i <= q; ++i)
        std::cout << res[i] << '\n';
    std::cerr << std::fixed << std::setprecision(6) << std::chrono::duration<double>(std::chrono::steady_clock::now() - stime).count() << "s\n";
    return 0;
}
/*
是只能换一次吗？不太能 ac 自动机。

找到 t 1 2 中不同的段，那么 s 1 2 中不同的段哈希值应该和这个相等
在不同段哈希值 上建 Trie，离线下来，左边 DFS + 回溯，右边 bit? 怎么这么复杂，还带只 log

无所谓了，就当 bit 常数小吧，想不到别的解法了
*/