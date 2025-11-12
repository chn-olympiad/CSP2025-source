#include <bits/stdc++.h>
#define rep(i, x, n) for(int i = x; i <= n; i ++)
#define dep(i, x, n) for(int i = x; i >= n; i --)
#define arrout(a, n) rep(i, 1, n) printk(a[i])
#define arrin(a, n) rep(i, 1, n) a[i] = read()
#define arrall(a, n) a + 1, a + 1 + n
#define all(x) x.begin(), x.end()
//#define int long long
#define CI const int
#define ss second
#define ff first

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

CI N = 1e6 + 5, B = 131, MOD = 993244853;
int n, q, ans, p[N] = { 1 }, hash1[N], hash2[N], hash[2][N];
std::string t1, t2;
std::pair<std::string, std::string> a[N];
int get1(int l, int r) { return l <= r ? (hash1[r] - hash1[l - 1] * p[r - l + 1] % MOD + MOD) % MOD : 0; }
int get2(int l, int r) { return l <= r ? (hash2[r] - hash2[l - 1] * p[r - l + 1] % MOD + MOD) % MOD : 0; }
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    rep(i, 1, N - 5) p[i] = p[i - 1] * B % MOD;
    n = read(), q = read();
    rep(i, 1, n) {
        std::cin >> a[i].ff >> a[i].ss, a[i].ff = " " + a[i].ff, a[i].ss = " " + a[i].ss;
        rep(j, 1, (int)a[i].ff.size() - 1) hash[0][i] = (hash[0][i] * B % MOD + a[i].ff[j]) % MOD;
        rep(j, 1, (int)a[i].ss.size() - 1) hash[1][i] = (hash[1][i] * B % MOD + a[i].ss[j]) % MOD;
    }
    while(q --) {
        ans = 0;
        std::cin >> t1 >> t2, t1 = " " + t1, t2 = " " + t2;
        rep(i, 1, (int)t1.size() - 1) hash1[i] = (hash1[i - 1] * B % MOD + t1[i]) % MOD;
        rep(i, 1, (int)t2.size() - 1) hash2[i] = (hash2[i - 1] * B % MOD + t2[i]) % MOD;
        rep(l, 1, (int)t1.size() - 1) rep(len, 1, (int)t1.size() - l) {
            int r = l + len - 1;
            rep(i, 1, n) if(get1(l, r) == hash[0][i]) ans += get1(1, l - 1) == get2(1, l - 1) && hash[1][i] == get2(l, r) && get1(r + 1, t1.size() - 1) == get2(r + 1, t2.size() - 1);
        }
        printl(ans);
    }
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0
*/
