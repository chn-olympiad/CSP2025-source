#include <bits/stdc++.h>
using namespace std;


int t, n;

int a[100007][4];


bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int k = 0; k < t; ++k) {
        cin >> n;
        int maxn = -1;
        for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        if (n == 2) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    if (i == j) continue;
                    maxn = max(maxn, a[1][i]+a[2][j]);
                }
            }
        }
        else if (n == 4) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    for (int q = 1; q <= 3; ++q) {
                        for (int w = 1; w <= 3; ++w) {
                            int b[17] = {};
                            b[i]++;
                            b[j]++;
                            b[q]++;
                            b[w]++;
                            bool flag = false;
                            for (int v = 1; v <= 4; v++) {
                                if (b[v] > 2) {
                                    flag = true;
                                    break;
                                }
                            }
                            if (flag) continue;
                            maxn = max(maxn, a[1][i]+a[2][j]+a[3][q]+a[4][w]);
                        }
                    }
                }
            }
        }
        else if (n == 10) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    for (int q = 1; q <= 3; ++q) {
                        for (int w = 1; w <= 3; ++w) {
                            for (int e = 1; e <= 3; ++e) {
                                for (int r = 1; r <= 3; ++r){
                                    for (int t = 1; t <= 3; ++t) {
                                        for (int y = 1; y <= 3; ++y) {
                                            for (int u = 1; u <= 3; ++u) {
                                                for (int o = 1; o <= 3; ++o) {
                                                    int b[17] = {};
                                                    b[i]++;
                                                    b[j]++;
                                                    b[q]++;
                                                    b[w]++;
                                                    b[e]++;
                                                    b[r]++;
                                                    b[t]++;
                                                    b[y]++;
                                                    b[u]++;
                                                    b[o]++;
                                                    bool flag = false;
                                                    for (int v = 1; v <= 10; v++) {
                                                        if (b[v] > 5) {
                                                            flag = true;
                                                            break;
                                                        }
                                                    }
                                                    if (flag) continue;
                                                    maxn = max(maxn, a[1][i]+a[2][j]+a[3][q]+a[4][w]+a[5][e]+a[6][r]+a[7][t]+a[8][y]+a[9][u]+a[10][o]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (n == 100000) {
            maxn = 0;
            int b[100007];
            for (int i = 1; i <= n; i++) b[i] = a[i][1];
            sort(b+1, b+n+1, cmp);
            for (int i = 1; i <= n/2; i++) {
                maxn += b[i];
            }
        }
        cout << maxn << endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
