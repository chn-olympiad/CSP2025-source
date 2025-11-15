#include <bits/stdc++.h>

long long fact(int n) {
    if (n == 1) return 1;
    return fact(n-1) * n;
}

int main() {
    std::ifstream input("employ.in");
    std::ofstream output("employ.out");
    int n, m;
    input >> n >> m;
    std::string s;
    input >> s;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        input >> c[i];
    }

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    long long f = fact(n);
    long long ans = 0;
    // std::cout << f << "\n";
    for (long long i = 0; i < f; i++) {
        // for (int i = 0; i < n; i++) {
        //     std::cout << p[i] << " ";
        // }
        // std::cout << "\n";

        int fails = 0;
        for (int j = 0; j < n; j++) {
            if (fails >= c[p[j]] || s[j] == '0') {
                fails++;
            }
        }

        if (n - fails >= m) {
            ans++;
        }

        std::next_permutation(p.begin(), p.end());
    }

    output << (ans % 998244353) << '\n';
}