#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 5e5 + 9;

int n, k;

int a[N], vis[N];

bool A = true, B = true;

std::vector<int> vec;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) A = false;
        if (a[i] > 1) B = false;
        if (a[i] == k) vec.emplace_back(i);
    }

    if (A) {
        printf("%d", n >> 1);
        return 0;
    }

    if (B) {
        if (k == 1) {
            int num = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] == 1)
                    num ++;
            printf("%d", num);
        }
        else {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0)
                    ans ++;
                if (a[i] == 1 && a[i - 1] == 1 && vis[i - 1] == 0) {
                    vis[i - 1] = 1, vis[i] = 1;
                    ans ++;
                }
            }
            printf("%d", ans);
        }
        return 0;
    }

    // if (n <= 1000) {
        int ans = vec.size();
        int l = 1;
        for (auto it : vec) {
            std::vector<std::pair<int, int>> v;
            for (int i = l; i < it; i++) {
                int x = a[i];
                for (int j = i + 1; j < it; j++) {
                    x ^= a[j];
                    if (x == k) {
                        v.emplace_back(i, j);
                        break;
                    }
                }
            }
            std::sort(v.begin(), v.end(), [](const std::pair<int, int>& x, const std::pair<int, int>& y) {
                return x.second < y.second;
            });
            int tot = 0, sc = v[0].second;
            while (true) {
                bool fg = 1;
                for (auto it2 : v) {
                    if (it2.first > sc) {
                        sc = it2.second;
                        tot++;
                        fg = 0;
                    }
                }
                if (fg)
                    break;
            }
            l = it + 1;
            ans += tot;
        }
        printf("%d", ans);
    // }

    fclose(stdin);
    fclose(stdout);

    return 0;
}