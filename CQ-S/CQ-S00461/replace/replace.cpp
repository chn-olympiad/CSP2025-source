#include <bits/stdc++.h>

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    constexpr unsigned long long K1 = 131, MOD1 = 1'765'215'131, K2 = 7, MOD2 = 2'433'204'337;
    std::vector<unsigned long long> V1(26), V2(26);
    std::mt19937_64 engine(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 26; i++) { V1[i] = engine() % MOD1; V2[i] = engine() % MOD2; }

    auto GetS = [&](std::string a, std::string b) {
        std::tuple<int, unsigned long long, unsigned long long> res(0, 0, 0);
        if (a == b) { return res; }
        int i = 0; while (a[i] == b[i]) { i++; }
        int j = a.size() - 1; while (a[j] == b[j]) { j--; }
        std::get<0>(res) = j - i + 1;
        for (int p = i; p <= j; p++) {
            std::get<1>(res) = (std::get<1>(res) * K1 % MOD1 + V1[a[p] - 'a']) % MOD1;
            std::get<2>(res) = (std::get<2>(res) * K2 % MOD2 + V2[a[p] - 'a']) % MOD2;
        }
        for (int p = i; p <= j; p++) {
            std::get<1>(res) = (std::get<1>(res) * K1 % MOD1 + V1[b[p] - 'a']) % MOD1;
            std::get<2>(res) = (std::get<2>(res) * K2 % MOD2 + V2[b[p] - 'a']) % MOD2;
        }
        return res;
    };

    int n, q; std::cin >> n >> q;
    std::vector<std::string> a(n + q + 1), b(n + q + 1);
    std::map<std::tuple<int, unsigned long long, unsigned long long>, std::vector<int>> buc;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
        buc[GetS(a[i], b[i])].emplace_back(i);
    }
    for (int i = 1; i <= q; i++) {
        std::cin >> a[n + i] >> b[n + i];
        if (a[n + i].size() == b[n + i].size()) { buc[GetS(a[n + i], b[n + i])].emplace_back(n + i); }
    }

    std::vector<int> Ans(q + 1);
    std::vector<int> pos(n + q + 1);
    for (auto W : buc) {
        int havePair = 0, haveQuery = 0;
        for (auto i : W.second) {
            if (i <= n) { havePair = 1; }
            if (i > n) { haveQuery = 1; }
        }
        if (!havePair || !haveQuery) { continue; }

        int dif = std::get<0>(W.first), L = 0;
        if (!dif) { continue; }
        for (auto i : W.second) { L += a[i].size() - dif; }

        int tot = 1; std::vector<int> trie(26 * (L + 2));
        auto id = [&](int x, int c) { return (x - 1) * 26 + c; };

        auto Insert = [&](std::string s) {
            int p = 1;
            for (auto i : s) {
                int &v = trie[id(p, i - 'a')];
                if (!v) { v = ++tot; } p = v;
            }
            return p;
        };
        for (auto i : W.second) {
            int j = 0; while (a[i][j] == b[i][j]) { j++; }
            std::string s = "";
            while (j > 0) { j--; s += a[i][j]; }
            pos[i] = Insert(s);
        }
        std::vector<int> dfn(tot + 1), out(tot + 1); int idx = 0;
        std::function<void(int)> DFS = [&](int x) {
            dfn[x] = ++idx;
            for (int i = (x - 1) * 26; i < x * 26; i++) {
                if (trie[i]) { DFS(trie[i]); }
            }
            out[x] = idx;
        }; DFS(1);

        std::fill(trie.begin(), trie.begin() + tot * 26, 0);
        int oto = 1;
        std::vector<std::vector<int>> con(L + 2);
        auto Tresni = [&](int x, std::string s) {
            int p = 1;
            for (auto i : s) {
                int &v = trie[id(p, i - 'a')];
                if (!v) { v = ++oto; } p = v;
            }
            con[p].emplace_back(x);
            return p;
        };
        for (auto i : W.second) {
            int j = a[i].size() - 1; while (a[i][j] == b[i][j]) { j--; }
            std::string s = "";
            while (j + 1 < (int)a[i].size()){ j++; s += a[i][j]; }
            Tresni(i, s);
        }

        std::vector<int> cnt(tot + 1);
        auto Add = [&](int x, int v) {
            for (int i = x; i > 0; i -= (i & -i)) { cnt[i] += v; }
        };
        auto RangeAdd = [&](int l, int r, int v) {
            if (l <= r) { Add(r, v); Add(l - 1, -v); }
        };
        auto Ask = [&](int x) {
            int res = 0;
            for (int i = x; i <= tot; i += (i & -i)) { res += cnt[i]; }
            return res;
        };
        std::function<void(int)> Evlos = [&](int x) {
            for (auto i : con[x]) {
                if (i <= n) { RangeAdd(dfn[pos[i]], out[pos[i]], 1); }
                if (i > n) { Ans[i - n] = Ask(dfn[pos[i]]); }
            }
            for (int i = (x - 1) * 26; i < x * 26; i++) {
                if (trie[i]) { Evlos(trie[i]); }
            }
            for (auto i : con[x]) {
                if (i <= n) { RangeAdd(dfn[pos[i]], out[pos[i]], -1); }
            }
        }; Evlos(1);
    }

    for (int i = 1; i <= q; i++) { std::cout << Ans[i] << '\n'; }

    return 0;
}