#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using string_pair = std::pair<std::string, std::string>;

constexpr int MAXN = 2e5 + 10;

int n, q;

int solve(std::string& t1, std::string& t2, std::vector<string_pair>& repl);

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    std::vector<string_pair> repl;
    for (int i = 0; i < n; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        repl.push_back(std::make_pair(s1, s2));
        // std::cout << "DEBUG: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << '\n';
    }

    for (int i = 1; i <= q; i++) {
        std::string t1, t2;
        std::cin >> t1 >> t2;
        // std::cout << "DEBUG: t1 = \"" << t1 << "\", t2 = \"" << t2 << "\"" << '\n';
        int ans = solve(t1, t2, repl);
        std::cout << ans << '\n';
    }

    return 0;
}

int solve(std::string& t1, std::string& t2, std::vector<string_pair>& repl) {
    int ans = 0;
    for (auto [s1, s2] : repl) {
        // std::cout << "DEBUG: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << '\n';
        int start_idx = 0;
        while (start_idx + s1.size() <= t1.size()) {
            // std::cout << "DEBUG: start_idx = " << start_idx << '\n';
            auto pos = t1.find(s1, start_idx);
            if (pos == std::string::npos) {
                break;
            }
            start_idx = pos + 1;
            std::string clone = t1;
            // std::cout << "DEBUG: clone = \"" << clone << "\"" << '\n';
            for (int i = 0; i < s1.size(); i++) {
                clone[pos + i] = s2[i];
            }
            if (clone == t2) {
                // std::cout << "DEBUG: ANS++" << '\n';
                ans++;
            }
        }
    }
    return ans;
}
