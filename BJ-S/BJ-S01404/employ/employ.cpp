// employ
#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read() {T x = 0; int f = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();} while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48); c = getchar();} return x * f;}
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
#define N 25
int n, m, s[N], c[N];
int res[N];
bool vis[N];
int ans = 0;
void dfs(int pos) {
    if (pos == n + 1) {
        int num = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (num >= c[res[i]] || !s[i]) {num++; continue;}
            num = 0; cnt++;
        }
        if (cnt >= m) ans++;
        return;
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = true;
        res[pos] = i;
        dfs(pos + 1);
        vis[i] = false;
    }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    n = read<int>(); m = read<int>();
    for (int i = 1; i <= n; i++) {
        char op = getchar();
        while (op != '0' && op != '1') op = getchar();
        s[i] = op ^ 48;
    }
    for (int i = 1; i <= n; i++) {
        c[i] = read<int>();
    }
    dfs(1); writeln(ans);

    return 0;
}
