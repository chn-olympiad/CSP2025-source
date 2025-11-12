#include <bits/stdc++.h>
#define rep(i, x, n) for(int i = x; i <= n; i ++)
#define dep(i, x, n) for(int i = x; i >= n; i --)
#define arrout(a, n) rep(i, 1, n) printk(a[i])
#define arrin(a, n) rep(i, 1, n) a[i] = read()
#define arrall(a, n) a + 1, a + 1 + n
#define all(x) x.begin(), x.end()
//#define int long long
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

CI N = 1e6 + 5;
int n, m, ans, a[N], num[N], vis[N];
std::string s;
void dfs(int step, int acc, int ref) {
    if(step > n) {
        rep(i, 1, n)
            if(ref >= a[num[i]]) ref ++;
            else if(s[i] == '1') acc ++;
            else ref ++;
        return ans += (acc >= m), void();
    }
    // if(step > n) return ans += (acc >= m), void();
    rep(i, 1, n) if(!vis[i]) vis[i] = 1, num[step] = i, dfs(step + 1, acc, ref), vis[i] = 0;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    n = read(), m = read();
    std::cin >> s, s = " " + s;
    arrin(a, n);
    dfs(1, 0, 0);
    print(ans);
	return 0;
}