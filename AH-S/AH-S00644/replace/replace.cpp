#include <bits/stdc++.h>
using namespace std;

#define filename "replace"
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

const int N = 5e6+2;

int n, q;

const int P1 = 1000092091, Base1 = 1049;
const int P2 = 1000020029, Base2 = 1171;

pii operator + (pii a, pii b) {
    return pii((a.first + b.first) % P1, (a.second + b.second) % P2);
}
pii operator * (pii a, pii b) {
    return pii((1ll * a.first * b.first) % P1, (1ll * a.second * b.second) % P2);
}

pii pw[N], table1[N], table2[N];

char s1[N], s2[N];
int len[N];
pii v1[N], v2[N];
char t1[N], t2[N];

void WaterM() {
    scanf("%d%d", &n, &q);

    upw(i, 1, n) {
        scanf("%s%s", s1+1, s2+1);
        len[i] = strlen(s1+1);
        pii val1 = pii(0, 0), val2 = pii(0, 0);
        upw(j, 1, len[i]) {
            val1 = val1 * pii(Base1, Base2) + pii(s1[j], s1[j]);
            //cerr << val1.first << ' ' << s1[i] << "    ";
            val2 = val2 * pii(Base1, Base2) + pii(s2[j], s2[j]);
        }
        v1[i] = val1, v2[i] = val2;
        //cerr << (s1+1) << '\n';
        //cerr << val1.first << ' ' << val1.second << '\n';
    }

    pw[0] = pii(1, 1);
    upw(i, 1, n) pw[i] = pw[i-1] * pii(Base1, Base2);

    upw(round, 1, q) {
        scanf("%s%s", t1+1, t2+1);
        int m = strlen(t1+1);
        int ans = 0;

        upw(i, 1, m) {
            table1[i] = table1[i-1] * pii(Base1, Base2) + pii(t1[i], t1[i]);
            table2[i] = table2[i-1] * pii(Base1, Base2) + pii(t2[i], t2[i]);
        }

        int p = -1, q = -1;
        upw(i, 1, m) if(t1[i] != t2[i]) q = i;
        dnw(i, m, 1) if(t1[i] != t2[i]) p = i;

        //cerr << p << ' ' << q << '\n';

        upw(i, q, m) {
            upw(j, 1, n) {
                if(i >= len[j] && i-len[j]+1 <= p) {
                    if(table1[i] == v1[j] + table1[i - len[j]] * pw[len[j]] &&
                       table2[i] == v2[j] + table2[i - len[j]] * pw[len[j]]) {
                        ++ans;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
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
