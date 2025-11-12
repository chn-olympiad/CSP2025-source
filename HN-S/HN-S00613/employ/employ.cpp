#include <iostream>

using namespace std;

const int N = 20, S = (1 << 20), mod = 998244353;

inline int pls(int x, int y) {return ((x + y >= mod) ? x + y - mod : x + y);}

int n, m, c[N], f[S][N];
char res[N];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    cin >> (res + 1);
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    f[0][0] = 1;

    for(int s = 0; s < (1 << n); s++) {
        int cnt = __builtin_popcount(s);

        if(cnt == n) {
            continue;
        }

        for(int i = 0; i <= cnt; i++) {
            if(f[s][i] == 0) {
                continue;
            }

            for(int j = 1; j <= n; j++) {
                if(((s >> (j - 1)) & 1) == 1) {
                    continue;
                }

                int nxt = (s | (1 << (j - 1))), fail = (res[cnt + 1] == '0' || i >= c[j]);

                f[nxt][i + fail] = pls(f[nxt][i + fail], f[s][i]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= n - m; i++) {
        ans = pls(ans, f[(1 << n) - 1][i]);
    }

    cout << ans << '\n';
}