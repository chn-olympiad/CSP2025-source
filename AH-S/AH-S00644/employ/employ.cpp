#include <bits/stdc++.h>
using namespace std;

#define filename "employ"
//#define multicases

#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

template<class T> bool vmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool vmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
template<class T> void clear(T &a) { a.swap(T()); }

const int N = 502;

const int P = 998244353;
void vadd(int &a, int b) { a += b; if(a >= P) a -= P; }

int n, m;
char s[N];
int c[N];

namespace sub1 {
    const int N = 22, MAXS = (1 << 18) | 2;
    int f[N][MAXS];
    void main() {
        f[0][0] = 1;
        upw(S, 0, (1 << n) - 1) {
            int sz = __builtin_popcount(S);
            upw(i, 0, n-1) {
                upw(j, 0, n-1) if(!(S & (1 << j))) {
                    int v = s[sz + 1] == '0' || c[j] <= i;
                    vadd(f[i+v][S | 1 << j], f[i][S]);
                    //cerr << i << ' ' << S << "    " << i+v << ' ' << (S | 1 << j) << "    " << s[sz + 1] << '\n';
                }
                //cerr << i << ' ' << S << "    " << f[i][S] << '\n';
            }
        }

        int ans = 0;
        upw(i, 0, n-m) vadd(ans, f[i][(1 << n) - 1]);
        cout << ans << '\n';
    }
}

void WaterM() {
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    upw(i, 0, n-1) cin >> c[i];

    if(n <= 18) return sub1::main();
}

signed main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif // filename

    signed _ = 1;
#ifdef multicases
    scanf("%d", &_);
#endif // multicases

    while(_--) WaterM();
}
