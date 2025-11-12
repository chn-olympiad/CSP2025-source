#include <cstdio>
int n, a[500005], k;
bool b[500005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int len = 0; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            bool f = 1;
            int sum = 0;
            for (int j = i; f && j <= i+len; j++) if (b[j]) f = 0; else sum ^= a[j];
            if (f && sum == k) {
                ans++;
                for (int j = i; j <= i+len; j++) b[j] = 1;
                i += len;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}