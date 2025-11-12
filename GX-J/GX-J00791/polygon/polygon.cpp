#include <cstdio>
#include <vector>
using namespace std;
int n, ans;
const int MAXN = 5e4 + 3;
int a[MAXN];
long long sum(const vector<int> v) {
    long long sum = 0;
    for (int i : v) {
        sum += a[i];
    }
    return sum;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int maxin(const vector<int> v) {
    int maxn = 0xcfcfcfcf;
    for (int i : v) {
        maxn = max(maxn, a[i]);
    }
    return maxn;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                v.push_back(j);
            }
        }
        if (cnt >= 3) {
            if (sum(v) > 2 * maxin(v)) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}
