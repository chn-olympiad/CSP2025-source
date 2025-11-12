#include <bits/stdc++.h>

using ull = unsigned long long;
const int N = 2e5 + 10;
const int M = 13331;
std::string a[N][2];
ull p[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;
    std::cin >> n >> q;
    std::vector<ull> hah(n), f;

    auto get_hash = [&](int l, int r) -> ull {
        return (l == 0 ? f[r] : f[r] - f[l - 1] * p[r - l + 1]);
    };

    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * M;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        std::string S = a[i][0];

        hah[i] = S[0] - 'a' + 1;
        for (int x = 1; x < S.size(); x++)
            hah[i] = hah[i] * M + (S[x] - 'a' + 1);
    }

    for (int i = 0; i < q; i++) {
        int cnt = 0;
        std::string sx, sy;
        std::cin >> sx >> sy;

        f.resize(sx.size());
        f[0] = sx[0] - 'a' + 1;
        for (int i = 1; i < sx.size(); i++) f[i] = f[i - 1] * M + (sx[i] - 'a' + 1);        

        for (int x = 0; x < n; x++) {
            std::string &S = a[x][0];
            for (int l = 0; l + S.size() <= sx.size(); l++) {
                if (get_hash(l, l + S.size() - 1) == hah[x]) {
                    std::string tmp = sx;
                    for (int dx = 0; dx < S.size(); dx++) {
                        tmp[l + dx] = a[x][1][dx];
                    }
                    if (tmp == sy) cnt++;
                }
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}