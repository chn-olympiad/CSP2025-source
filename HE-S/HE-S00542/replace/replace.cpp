#include <bits/stdc++.h>



int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out", "w",stdout);
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<std::string, std::string>> v(n);
    for (int i = 0; i<n;i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        v[i] = std::make_pair(s1, s2);
    }
    for (int i=0; i<q; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
    }
    return 0;
}
