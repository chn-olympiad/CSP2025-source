#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
const int N1 = 2e4 + 1;

int n, m[N], r[N], ans = 0;

void sort1() {
    int s[N1];
    s[0] = { 0 };
    for (int i = 1; i <= n; ++i) ++s[m[i]];
    for (int i = 1; i <= 2e4 + 1; ++i) s[i] += s[i - 1];
    for (int i = n; i >= i; --i) {
        r[s[m[i]]] = m[i];
        --s[m[i]];
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        int tmp;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (j == 1) cin >> m[i];
                else cin >> tmp;
            }
        }
        sort1();
        for (int i = n / 2; i >= 1; --i) ans += r[i];
        cout << ans;
    }
    return 0;
}
