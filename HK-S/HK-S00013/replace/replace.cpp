#include <bits/stdc++.h>

bool cansub(std::string a, std::string b, std::string c, std::string d) {
    int l1 = a.length();
    int l2 = c.length();

    for (int i = 0; i <= l1 - l2; i++) {
        int ok = 1;
        for (int j = 0; j < l2; j++) {
            if (a[i+j] != c[j] || b[i+j] != d[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    std::ifstream input("replace.in");
    std::ofstream output("replace.out");
    int n, q;
    input >> n >> q;
    std::vector<std::pair<std::string, std::string>> s(n);
    std::vector<int> rr(n);
    // std::vector<int> diffs(n);
    std::vector<std::vector<int>> bydiff(n+10, std::vector<int>());
    for (int i = 0; i < n; i++) {
        std::string a, b;
        input >> a >> b;
        // std::cout << "a:" << a << "  b:" << b << "\n";
        s[i] = {a, b};
        int d = 0;
        int start = -1, end = -1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                d++;
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
        }
        if (d == 0) {
            rr[i] = 0;
        } else {
            rr[i] = end - start + 1;
        }
        // diffs[i] = d;
        bydiff[d].push_back(i);
    }

    while (q--) {
        std::string a, b;
        input >> a >> b;
        std::vector<int> cmpp(a.length());
        int diff = 0;
        int start = -1, end = -1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
        }
        int ran = 0;
        if (diff != 0) {
            ran = end - start + 1;
        }
        int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     std::string c = s[i].first;
        //     std::string d = s[i].second;
        //     if (cansub(a, b, c, d, cmpp, diff)) {
        //         ans++;
        //     }
        // }

        for (int i : bydiff[diff]) {
            std::string c = s[i].first;
            std::string d = s[i].second;
            if (ran == rr[i]) {
                if (cansub(a, b, c, d)) {
                    ans++;
                }
            }
        }

        output << ans << "\n";
    }
}