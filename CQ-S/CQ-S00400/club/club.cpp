#include <bits/stdc++.h>
#define rep(i, x, n) for(int i = x; i <= n; i ++)
#define dep(i, x, n) for(int i = x; i >= n; i --)
#define arrout(a, n) rep(i, 1, n) printk(a[i])
#define arrin(a, n) rep(i, 1, n) a[i] = read()
#define arrall(a, n) a + 1, a + 1 + n
#define all(x) x.begin(), x.end()
#define PII std::pair<int, int>
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

CI N = 1e6 + 5;
int T, n, ans, cnt1, cnt2, cnt3, id[N], vis[N];
struct Node {
    int x, y, z;
    bool operator<(const Node& b) const {
        int ma1 = std::max({ x, y, z }), ma2 = std::max({ b.x, b.y, b.z });
        int se1, se2;
        if(x == ma1) se1 = std::max(y, z);
        if(y == ma1) se1 = std::max(x, z);
        if(z == ma1) se1 = std::max(x, y);
        if(b.x == ma2) se2 = std::max(b.y, b.z);
        if(b.y == ma2) se2 = std::max(b.x, b.z);
        if(b.z == ma2) se2 = std::max(b.x, b.y);
        return ma1 - se1 > ma2 - se2;
    }
} a[N];
std::priority_queue<Node> q1, q2, q3;
// void dfs(int step, int sum, int c1, int c2, int c3) {
//     if(step > n) return ans = std::max(ans, sum), void();
//     if(c1 < n / 2) id[step] = 1, dfs(step + 1, sum + a[step].x, c1 + 1, c2, c3);
//     if(c2 < n / 2) id[step] = 2, dfs(step + 1, sum + a[step].y, c1, c2 + 1, c3);
//     if(c3 < n / 2) id[step] = 3, dfs(step + 1, sum + a[step].z, c1, c2, c3 + 1);
// }
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    T = read();
    while(T --) {
        n = read(), ans = 0;
        rep(i, 1, n) a[i] = (Node) { read(), read(), read() };
        rep(i, 1, n) {
            if(a[i].x >= std::max(a[i].y, a[i].z) && !vis[i]) q1.push(a[i]), vis[i] = 1;
            if(a[i].y >= std::max(a[i].x, a[i].z) && !vis[i]) q2.push(a[i]), vis[i] = 1;
            if(a[i].z >= std::max(a[i].x, a[i].y) && !vis[i]) q3.push(a[i]), vis[i] = 1;
        }
        while((int)q1.size() > n / 2) {
            auto u = q1.top(); q1.pop();
            if(u.y > u.z) q2.push(u);
            else q3.push(u);
        }
        while((int)q2.size() > n / 2) {
            auto u = q2.top(); q2.pop();
            if(u.x > u.z) q1.push(u);
            else q3.push(u);
        }
        while((int)q3.size() > n / 2) {
            auto u = q3.top(); q3.pop();
            if(u.x > u.y) q1.push(u);
            else q2.push(u);
        }
        while(!q1.empty()) ans += q1.top().x, q1.pop();
        while(!q2.empty()) ans += q2.top().y, q2.pop();
        while(!q3.empty()) ans += q3.top().z, q3.pop();
        rep(i, 1, n) vis[i] = 0;
        // dfs(1, 0, 0, 0, 0);
        printl(ans);
    }
	return 0;
}
/*
1
5
3 1 2 
7 6 10 
3 4 8 
8 6 1 
8 3 3 

37
*/
