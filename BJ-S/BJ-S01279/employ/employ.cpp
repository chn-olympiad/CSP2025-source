#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
#define int long long
#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 505

using namespace std;

const int mod = 998244353;

int n, m, s[maxn], c[maxn];

string str;

namespace WorkA {
    int f[2][maxn][maxn], g[maxn][maxn];
    void worka() {
        memset(f, 0, sizeof(f));
        int p = 0, q = 1;
        f[p][0][0] = 1;
        for(int i = 1; i <= n; i++) {
            memset(f[q], 0, sizeof(f[q]));
            memset(g, 0, sizeof(g));
            for(int j = 0; j <= i; j++) {
                for(int k = 0; k <= j; k++) {
                    if(k + i - j - 1 >= 0) (f[q][j][k] += (k + i - j - 1) * f[p][j][k]) %= mod;

                    if(j - c[i] + 1 >= 0) (f[q][j + 1][k] += (j - c[i] + 1) * f[p][j][k]) %= mod;

                    int l = k + i - j, r = c[i] + i - j;
                    l = max(l, 0ll), r = min(r, i + 1);
                    if(l < r) (g[j][j - i + l] += f[p][j][k]) %= mod, (g[j][j - i + r] -= f[p][j][k]) %= mod;
                }
            }
            for(int j = 0; j <= i; j++) {
                for(int k = 0; k <= j; k++) {
                    if(k >= 1) (g[j][k] += g[j][k - 1]) %= mod;
                    (f[q][j][k] += g[j][k]) %= mod;
                }
            }
            p ^= 1, q ^= 1;
        }
        int sum = 0;
        for(int j = 0; j <= n - m; j++) {
            for(int k = 0; k <= j; k++) {
                (sum += f[p][j][k]) %= mod;
            }
        }
        cout << (sum % mod + mod) % mod << '\n';
    }
}

namespace WorkB {
#define maxN 270005
    int f[2][maxN][23], g[maxN][23], h[maxN][23];
    vector<int> G;
    void workb() {
        // exit(0);
        int cnt = 0, t = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == 0) cnt++;
            else G.push_back(i);
        }
        t = G.size();
        memset(f, 0, sizeof(f));
        // cout << t << endl;
        // exit(0);
        int p = 0, q = 1;
        f[p][0][0] = 1;
        for(int i = 1; i <= n; i++) {
            // cerr << i << endl;
            memset(f[q], 0, sizeof(f[q]));
            // memset(g, 0, sizeof(g));
            // memset(h, 0, sizeof(h));
            for(int s = 0; s < (1 << t); s++) {
                int pcs = __builtin_popcountll(s);
                for(int j = 0; j <= t; j++) (f[q][s][j] += f[p][s][j]) %= mod;
                for(int k = 0; k < t; k++) {
                    if((s >> k) & 1) continue;
                    int _s = s | (1 << k);
                    int tv = cnt + pcs - (n - G[k]) + __builtin_popcountll(((1 << t) - 1 - s) >> k) - 1 - c[i];

                    // for(int j = 0; j <= tv && j ; j++) {
                    //     (f[q][_s][j] += f[p][s][j]);// %= mod;
                    // }
                    // for(int j = tv + 1; j <= pcs; j++) {
                    //     (f[q][_s][j + 1] += f[p][s][j]);// %= mod;
                    // }

                    // g[_s][0]++;
                    // g[_s][tv + 1]--;
                    // h[_s][tv + 1]++;
                    // h[_s][t + 1]--;
                    
                    for(int j = 0; j <= t; j++) {
                        if(tv >= j) {
                            (f[q][_s][j] += f[p][s][j]);// %= mod;
                        }
                        else {
                            (f[q][_s][j + 1] += f[p][s][j]);// %= mod;
                        }
                    }
                }
            }
            for(int s = 0; s < (1 << t); s++) {
                for(int j = 0; j <= t; j++) {
                    // if(j >= 1) h[s][j] += h[s][j - 1], g[s][j] += g[s][j - 1];
                    // f[q][s][j] += f[p][s][j] * g[s][j];
                    // if(j >= 1) f[q][s][j] += f[p][s][j - 1] * h[s][j];
                    f[q][s][j] %= mod;
                }
            }
            p ^= 1, q ^= 1;

            // if(i == 1) cout << f[p][1][1] << "#" << endl;
        }
        int sum = 0;
        for(int j = m; j <= t; j++) {
            (sum += f[p][(1 << t) - 1][j]) %= mod;
        }
        for(int i = 1; i <= cnt; i++) (sum *= i) %= mod;
        cout << (sum % mod + mod) % mod << '\n';
    }
}

void work() {
    cin >> n >> m >> str;
    int sum = 0;
    for(int i = 1; i <= n; i++) s[i] = str[i - 1] - '0', sum += s[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(sum < m) {
        cout << "0\n";
        return ;
    }
    sort(c + 1, c + n + 1);
    if(sum == n) {
        WorkA::worka();
    }
    else if(sum <= 18) WorkB::workb();
}

signed main() {
    fopen("employ");
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_--) work();
}