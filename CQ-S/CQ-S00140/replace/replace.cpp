#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXL = 5e6, MAXN = 2e5;
int n, q;
char s[MAXL + 5], t[MAXL + 5], tmp[MAXL + 5], tmp2[MAXL + 56];
int L[MAXN + 5], R[MAXN + 5];

const unsigned long long Base = 133;
unsigned long long Hs[MAXL + 5];
unsigned long long Ht[MAXL + 5];
unsigned long long HHs[MAXL + 5];
unsigned long long HHt[MAXL + 5];
unsigned long long P[MAXL + 5];
unsigned long long QueryS(int l, int r) {
    return Hs[r] - Hs[l - 1] * P[r - l + 1];
}
unsigned long long QueryT(int l, int r) {
    return Ht[r] - Ht[l - 1] * P[r - l + 1];
}
unsigned long long QueryHs(int l, int r) {
    return HHs[r] - HHs[l - 1] * P[r - l + 1];
}
unsigned long long QueryHt(int l, int r) {
    return HHt[r] - HHt[l - 1] * P[r - l + 1];
}
int main() {
    #ifndef LOCAL
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    #else
    freopen("./replace/replace2.in", "r", stdin);
    freopen("code.out", "w", stdout);
    clock_t BEGINT = clock();
    #endif
    P[0] = 1;
    for (int i = 1; i <= MAXL; i ++) P[i] = P[i - 1] * Base;
    scanf("%d%d", &n, &q);
    int Len = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%s", tmp + 1);
        scanf("%s", tmp2 + 1);
        int len = strlen(tmp + 1);
        L[i] = Len + 1; R[i] = Len + len;
        for (int j = Len + 1; j <= Len + len; j ++) {
            s[j] = tmp[j - Len];
            t[j] = tmp2[j - Len];
        }
        Len += len;
    }
    for (int i = 1; i <= Len; i ++) Hs[i] = Hs[i - 1] * Base + s[i];
    for (int i = 1; i <= Len; i ++) Ht[i] = Ht[i - 1] * Base + t[i];

    Len = 0;
    for (int i = 1; i <= q; i ++) {
        scanf("%s", tmp + 1);
        scanf("%s", tmp2 + 1);
        int len = strlen(tmp + 1);

        for (int i = 1; i <= len; i ++) HHs[i] = HHs[i - 1] * Base + tmp[i];
        for (int i = 1; i <= len; i ++) HHt[i] = HHt[i - 1] * Base + tmp2[i];
        int ans = 0;
        for (int j = 1; j <= n; j ++) {
            for (int p = 1; p + (R[j] - L[j] + 1) - 1 <= len; p ++) {
                if (QueryHs(1, p - 1) == QueryHt(1, p - 1) && QueryHs(p + (R[j] - L[j] + 1), len) == QueryHt(p + (R[j] - L[j] + 1), len) &&QueryS(L[j], R[j]) == QueryHs(p, p + (R[j] - L[j] + 1) - 1) && QueryT(L[j], R[j]) == QueryHt(p, p + (R[j] - L[j] + 1) - 1)) {
                    ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    

    #ifdef LOCAL
    clock_t ENDT = clock();
    cerr<<endl<<fixed<<setprecision(3)<<(double)(ENDT - BEGINT) / CLOCKS_PER_SEC;
    #endif
    return 0;
}