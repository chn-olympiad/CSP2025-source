#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int t, n, ans;
int cnt1, cnt2, cnt3;
int seq1[MAXN], seq2[MAXN], seq3[MAXN];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        ans = cnt1 = cnt2 = cnt3 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int temp1, temp2, temp3; scanf("%d %d %d", &temp1, &temp2, &temp3);
            if (temp1 >= max(temp2, temp3)) {
                seq1[++cnt1] = temp1 - max(temp2, temp3);
                ans += temp1;
            } else if (temp2 >= max(temp1, temp3)) {
                seq2[++cnt2] = temp2 - max(temp1, temp3);
                ans += temp2;
            } else {
                seq3[++cnt3] = temp3 - max(temp1, temp2);
                ans += temp3;
            }
        }
        if (cnt1 > n / 2) {
            sort(seq1 + 1, seq1 + cnt1 + 1);
            int temp = cnt1 - n / 2;
            for (int i = 1; i <= temp; i++) {
                ans -= seq1[i];
            }
        }
        if (cnt2 > n / 2) {
            sort(seq2 + 1, seq2 + cnt2 + 1);
            int temp = cnt2 - n / 2;
            for (int i = 1; i <= temp; i++) {
                ans -= seq2[i];
            }
        }
        if (cnt3 > n / 2) {
            sort(seq3 + 1, seq3 + cnt3 + 1);
            int temp = cnt3 - n / 2;
            for (int i = 1; i <= temp; i++) {
                ans -= seq3[i];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}