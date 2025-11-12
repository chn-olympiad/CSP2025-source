#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
    x = 0; char ch = getchar(); bool ff = 0;
    while(ch < '0' || ch > '9') ff |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
    x = ff ? -x : x;
}
template <typename T, typename ...T1> void read(T &x, T1 &...x1) {
    read(x); read(x1...);
}
#define int long long
const int maxn = 1e3 + 5, mod = 998244353;
int n, m;
char s[maxn];
struct node {
    int id, v;
    node(int id = 0, int v = 0): id(id), v(v) {}
    friend bool operator == (node e1, node e2) {
        return e1.id == e2.id && e1.v == e2.v;
    }
    friend bool operator < (node e1, node e2) {
        return e1.v ^ e2.v ? e1. v < e2.v : e1.id < e2.id;
    }
} c[maxn];
bool check() {
    int tot = 0, sum = 0;
    for(int i = 1; i <= n; i ++) {
            //cout << tot << " ";
        if(s[i] == '0') {
            tot ++;
            continue;
        }
        if(tot >= c[i].v) continue;
        sum ++;
    }//cout << endl;
    //for(int i = 1; i <= n; i ++) cout << c[i].v << " "; cout << endl;
    //cout << sum << endl;
    return sum >= m;
}
void Solve() {
    read(n, m);
    scanf("%s", s + 1);
    for(int i = 1, x; i <= n; i ++) read(x), c[i] = node(i, x);
    sort(c + 1, c + n + 1);
    int ans = 0;
    do {
        if(check()) ans ++, ans %= mod;
    } while(next_permutation(c + 1, c + n + 1));
    printf("%lld\n", ans);
}
#undef int
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    Solve();
    return 0;
}
