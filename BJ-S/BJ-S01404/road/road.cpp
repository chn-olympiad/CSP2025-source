// road
#include <bits/stdc++.h>
using namespace std;
char buf[1 << 22], *p1 = buf, *p2 = buf;
#define gc() ((p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)) ? EOF : *p1++)
template <typename T>
T read() {T x = 0; int f = 1; char c = gc(); while (c < '0' || c > '9') {if (c == '-') f = -1; c = gc();} while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48); c = gc();} return x * f;}
template <typename T>
void write(T x) {if (x < 0) {putchar('-'); x = -x;} if (x > 9) write(x / 10); putchar('0' + x % 10);}
template <typename T>
void writeln(T x) {write(x); putchar('\n');}
template <typename T>
void write(T x, char c) {write(x); putchar(c);}
template <typename T>
T min_(T x, T y) {return x < y ? x : y;}
template <typename T>
T max_(T x, T y) {return x < y ? y : x;}
#define N 10025
#define M 2000005
#define K 15
#define ll long long
#define INF 0x3f3f3f3f
int n, m, k, c[K];
struct node {
    int v, w;
    node () {}
    node (int v, int w): v(v), w(w) {}
    friend bool operator < (node a, node b) {return a.w > b.w;}
};
node vl[M << 1];
int hd[N], nx[M << 1], cnt_edge = 1;
void add_edge(int u, int v, int w) {
    vl[++cnt_edge] = node(v, w);
    nx[cnt_edge] = hd[u];
    hd[u] = cnt_edge;
}
struct node_ {
    int x, y, z;
    node_ () {}
    node_ (int x, int y, int z): x(x), y(y), z(z) {}
    friend bool operator < (node_ a, node_ b) {return a.z < b.z;}
};
node_ ed[M];
int cnted = 0;
int pre[N], siz[N];
int find_(int i) {return pre[i] == i ? i : pre[i] = find_(pre[i]);}
void join_(int i, int j) {
    i = find_(i); j = find_(j);
    if (i == j) return;
    if (siz[i] > siz[j]) {pre[j] = i; siz[i] += siz[j];}
    else {pre[i] = j; siz[j] += siz[i];}
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    n = read<int>(); m = read<int>(); k = read<int>();
    for (int i = 1; i <= m; i++) {
        int x, y, z; x = read<int>(); y = read<int>(); z = read<int>();
        add_edge(x, y, z); add_edge(y, x, z);
        ed[++cnted] = node_(x, y, z);
    }
    for (int i = 1; i <= k; i++) {
        c[i] = read<int>();
        for (int j = 1; j <= n; j++) {
            int x = read<int>();
            add_edge(j, n + i, x); add_edge(n + i, j, x);
            ed[++cnted] = node_(j, n + i, x);
        }
    }
    sort(ed + 1, ed + cnted + 1);
    ll ans = 0x3f3f3f3f3f3f3f3fLL;
    for (int X = 0; X < (1 << k); X++) {
        for (int i = 1; i <= n + k; i++) {pre[i] = i; siz[i] = 1;}
        ll sum = 0;
        int numX = 0;
        for (int i = 1; i <= k; i++) if ((X >> (i - 1)) & 1) numX++;
        int num = 0;
        for (int i = 1; i <= cnted && num < n + numX - 1; i++) {
            int x = ed[i].x, y = ed[i].y;
            if (x > n && !((X >> (x - n - 1)) & 1)) continue;
            if (y > n && !((X >> (y - n - 1)) & 1)) continue;
            if (find_(x) == find_(y)) continue;
            num++; sum += ed[i].z; join_(x, y);
        }
        for (int i = 1; i <= k; i++) if ((X >> (i - 1)) & 1) sum += c[i];
        ans = min_(ans, sum);
    }
    writeln(ans);

    return 0;
}
