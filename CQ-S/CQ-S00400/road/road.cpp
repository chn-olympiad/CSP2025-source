#include <bits/stdc++.h>
#define rep(i, x, n) for(int i = x; i <= n; i ++)
#define dep(i, x, n) for(int i = x; i >= n; i --)
#define arrout(a, n) rep(i, 1, n) printk(a[i])
#define arrin(a, n) rep(i, 1, n) a[i] = read()
#define arrall(a, n) a + 1, a + 1 + n
#define all(x) x.begin(), x.end()
#define p_b push_back
#define int long long
#define CI const int

int read() {
	char ch = getchar();
	int r = 0, w = 1;
	while(ch < '0' || ch > '9') w = ch == '-' ? -1 : w, ch = getchar();
	while(ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
	return r * w;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
} template<typename ...Args>
void print(int x, Args... args) { print(x), print(args...); }

void printk(int x) { print(x), putchar(' '); }
template<typename ...Args>
void printk(int x, Args... args) { printk(x), printk(args...); }

void printl(int x) { print(x), putchar('\n'); }
template<typename ...Args>
void printl(int x, Args... args) { printl(x), printl(args...); }

CI N = 1e4 + 5, M = 2e6 + 5;
int n, m, k, t, ans = 1e18, cnt, c[N], fa[N + 10], a[15][N];
struct Edge {
    int from, to, data;
    bool operator<(const Edge& b) const { return data < b.data; }
};
std::multiset<Edge> e;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int kruscal() {
    int cnt = 0, res = 0;
    rep(i, 1, n + k) fa[i] = i;
    // std::sort(all(e));
    for(auto i : e) {
		int x = find(i.from), y = find(i.to), z = i.data;
        if(x ^ y) {
            fa[x] = y, res += z;
            if(++cnt == n + t - 1) break;
        }
    }
    return res;
}
int popcount(int x) {
    int res = 0;
    while(x) res += x & 1, x >>= 1;
    return res;
}
signed main() {
    // printl((log2(1e3 + 5) * log2(1e6 + 1e3 * 5) + 2 * (1e3) * log2(1e6 + 1e3 + 5)) * 32);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    rep(i, 1, m) e.insert((Edge) { read(), read(), read() });
    int flag = 0;
    rep(i, 1, k) {
        flag += c[i] = read();
        rep(j, 1, n) a[i][j] = read();
    }
    if(!flag) {
    	t = 0;
		int sum = 0;
        rep(j, 1, k) {
            t ++, sum += c[j];
            rep(l, 1, n) e.insert((Edge) { n + j, l, a[j][l] });
        }
        print(kruscal() + sum), exit(0);
	}
    rep(i, 0, (1 << k) - 1) {
        t = 0;
        int sum = 0;
        rep(j, 1, k) if((i >> (j - 1)) & 1) {
            t ++, sum += c[j];
            if((i - 1) >> (j - 1) & 1) continue;
            rep(l, 1, n) e.insert((Edge) { n + j, l, a[j][l] });
        }
        ans = std::min(ans, kruscal() + sum);
        rep(j, 1, k) if((i >> (j - 1)) & 1) {
            if((i + 1) >> (j - 1) & 1) continue;
            rep(l, 1, n) e.erase((Edge) { n + j, l, a[j][l] });
        }
    }
    print(ans);
	return 0;
}
