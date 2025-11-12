#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
string l1[maxn], l2[maxn];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        cin >> l1[i] >> l2[i];
    }
    for (int i = 1; i <= q; i++) {
        int ans = 0;
        string s1, s2;
        cin >> s1 >> s2;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < s1.length() - l1[j].length() + 1; k++) {
                if (s1.substr(k, k + l1[j].length() - 1) == l1[j]
                    && s2.substr(k, k + l2[j].length() - 1) == l2[j]) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
