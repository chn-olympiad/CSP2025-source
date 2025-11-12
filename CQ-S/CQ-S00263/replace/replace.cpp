#include <bits/stdc++.h>
struct binary_indexed_tree {
    std::vector<int> tree;
    binary_indexed_tree(int n) : tree(n) {}
    constexpr static int lowbit(int x) { return x & -x; }
    void add(int x, int y) {
        for (int i = x + 1; i <= tree.size(); i += lowbit(i))
            tree[i - 1] += y;
        return;
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x + 1; i > 0; i -= lowbit(i))
            ans += tree[i - 1];
        return ans;
    }
};
struct intrie {
    struct node {
        std::array<int, 26> ch{};
        int dfn = -1, siz = 0;
    };
    int doc;
    std::vector<node> t;
    int new_node() {
        int x = t.size();
        t.emplace_back();
        return x;
    }
    intrie() : doc(0) {}
    int insert(const std::string &s) {
        if (t.empty())
            new_node();
        int p = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!t[p].ch[x]) {
                int z = new_node();
                t[p].ch[x] = z;
            }
            p = t[p].ch[x];
        }
        return p;
    }
    void dfs(int x) {
        t[x].dfn = doc++;
        t[x].siz = 1;
        for (int y : t[x].ch)
            if (y)
                dfs(y), t[x].siz += t[y].siz;
        return;
    }
};
struct trie {
    struct node {
        std::array<int, 26> ch{};
        intrie t;
        std::vector<std::pair<int, int>> f;
        std::vector<std::tuple<int, int, int>> g;
    };
    std::vector<node> t;
    int new_node() {
        int x = t.size();
        t.emplace_back();
        return x;
    }
    trie() {}
    int insert(const std::string &s) {
        if (t.empty())
            new_node();
        int p = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!t[p].ch[x]) {
                int z = new_node();
                t[p].ch[x] = z;
            }
            p = t[p].ch[x];
        }
        return p;
    }
    void insert1(const std::string &s, const std::string &t1, const std::string &t2) {
        int p = insert(s);
        int x = t[p].t.insert(t1);
        int y = t[p].t.insert(t2);
        t[p].f.emplace_back(x, y);
        return;
    }
    void insert2(const std::string &s, int i, const std::string &t1, const std::string &t2) {
        int p = insert(s);
        int x = t[p].t.insert(t1);
        int y = t[p].t.insert(t2);
        t[p].g.emplace_back(x, y, i);
        return;
    }
    void make(int x, std::vector<int> &ans) {
        if (!t[x].f.empty() && !t[x].g.empty()) {
            binary_indexed_tree bit(t[x].t.t.size());
            t[x].t.dfs(0);
            std::vector<std::tuple<int, int, int, int>> f;
            for (auto [u, v] : t[x].f) {
                f.emplace_back(t[x].t.t[u].dfn, -1, t[x].t.t[v].dfn, t[x].t.t[v].dfn + t[x].t.t[v].siz);
                f.emplace_back(t[x].t.t[u].dfn + t[x].t.t[u].siz, -1, t[x].t.t[v].dfn + t[x].t.t[v].siz, t[x].t.t[v].dfn);
            }
            for (auto [u, v, w] : t[x].g)
                f.emplace_back(t[x].t.t[u].dfn, w, t[x].t.t[v].dfn, t[x].t.t[v].dfn);
            std::sort(f.begin(), f.end());
            for (auto [x, y, z, w] : f)
                if (~y)
                    ans[y] = bit.sum(z);
                else
                    bit.add(z, 1), bit.add(w, -1);
        }
        for (int y : t[x].ch)
            if (y)
                make(y, ans);
        return;
    }
};
int main() {
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    trie tt;
    for (int i = 0; i < n; i++) {
        std::array<std::string, 2> s;
        std::cin >> s[0] >> s[1];
        if (s[0] == s[1])
            continue;
        int l = 0, r = s[0].length();
        while (l < s[0].length() && s[0][l] == s[1][l])
            l++;
        while (r > 0 && s[0][r - 1] == s[1][r - 1])
            r--;
        tt.insert1(std::string(s[0].begin() + l, s[0].begin() + r) + std::string(s[1].begin() + l, s[1].begin() + r), std::string(s[0].rend() - l, s[0].rend()), std::string(s[0].begin() + r, s[0].end()));
    }
    for (int i = 0; i < q; i++) {
        std::array<std::string, 2> t;
        std::cin >> t[0] >> t[1];
        if (t[0].size() != t[1].size())
            continue;
        int l = 0, r = t[0].length();
        while (l < t[0].length() && t[0][l] == t[1][l])
            l++;
        while (r > 0 && t[0][r - 1] == t[1][r - 1])
            r--;
        tt.insert2(std::string(t[0].begin() + l, t[0].begin() + r) + std::string(t[1].begin() + l, t[1].begin() + r), i, std::string(t[0].rend() - l, t[0].rend()), std::string(t[0].begin() + r, t[0].end()));
    }
    std::vector<int> ans(q);
    tt.make(0, ans);
    for (int i = 0; i < q; i++)
        std::cout << ans[i] << '\n';
    return 0;
}