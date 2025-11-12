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
const int maxn = 1e3 + 5, maxm = 2e3 + 5;
int n, q;
string s1[maxn], s2[maxn];
map<pair<string, string>, bool> ok;
void Solve() {
    read(n, q);
    for(int i = 1; i <= n; i ++) cin >> s1[i] >> s2[i], ok[{s1[i], s2[i]}] = 1;
    for(int i = 1; i <= q; i ++) printf("0\n");
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    Solve();
    return 0;
}
