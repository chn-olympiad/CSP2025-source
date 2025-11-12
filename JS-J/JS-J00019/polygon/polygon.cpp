#include <bits/stdc++.h>
using namespace std;
int n, s[5005], a123, a12;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    //if (n == 0)
    if (n >= 3) {
        for (int i = 1; i <= n; ++i) {
            a123 = s[i];
            //m12 = 0;
            for (int j = i + 1; j <= n; ++j) {
                a123 += s[j];
                //m12 = 0;
                for (int k = j + 1; k <= n; ++k) {
                    a123 += s[k];
                    //m12 = 0;
                    if (n >= 4) {
                        for (int l = k + 1; l <= n; ++l) {
                            a123 += s[l];
                            //m12 = 0;
                            if (n >= 5) {
                                for (int x = l + 1; x <= n; ++x) {
                                    a123 += s[x];
                                    //m12 = 0;
                                    if (n >= 6) {
                                        for (int y = x + 1; y <= n; ++y) {
                                            a123 += s[y];
                                            if (n >= 7) {
                                                for (int v = y + 1; v <= n; ++v) {
                                                    a123 += s[v];
                                                    if (n >= 8) {
                                                        for (int w = v + 1; w <= n; ++w) {
                                                            a123 += s[w];
                                                            if (n >= 9) {
                                                                for (int q = w + 1; q <= n; ++q) {
                                                                    a123 += s[q];
                                                                    if (n >= 10) {
                                                                        for (int p = q + 1; p <= n; ++p) {
                                                                            a123 += s[p];
                                                                            if (a123 > (s[p] * 2)) {
                                                                                a12++;
                                                                                a12 %= 998244353;
                                                                                //m12 = 1;
                                                                                //cout << 6;
                                                                            }
                                                                            a123 -= s[p];
                                                                        }
                                                                    }
                                                                    if (a123 > (s[q] * 2)) {
                                                                        a12++;
                                                                        a12 %= 998244353;
                                                                        //m12 = 1;
                                                                        //cout << 6;
                                                                    }
                                                                    a123 -= s[q];
                                                                }
                                                            }
                                                            if (a123 > (s[w] * 2)) {
                                                                a12++;
                                                                a12 %= 998244353;
                                                                //m12 = 1;
                                                                //cout << 6;
                                                            }
                                                            a123 -= s[w];
                                                        }
                                                    }
                                                    if (a123 > (s[v] * 2)) {
                                                        a12++;
                                                        a12 %= 998244353;
                                                        //m12 = 1;
                                                        //cout << 6;
                                                    }
                                                    a123 -= s[v];
                                                }
                                            }
                                            if (a123 > (s[y] * 2)) {
                                                a12++;
                                                a12 %= 998244353;
                                                //m12 = 1;
                                                //cout << 6;
                                            }
                                            a123 -= s[y];
                                        }
                                    }
                                    if (a123 > (s[x] * 2)) {
                                        a12++;
                                        a12 %= 998244353;
                                    }
                                    a123 -= s[x];
                                }
                            }
                            if (a123 > (s[l] * 2)) {
                                a12++;
                                a12 %= 998244353;
                            }
                            a123 -= s[l];
                        }
                    }
                    if (a123 > (s[k] * 2)) {
                        a12++;
                        a12 %= 998244353;
                    }
                    a123 -= s[k];
                }
                a123 -= s[j];
            }
            a123 -= s[i];
        }
    }
    printf("%d", a12);
    return 0;
}
