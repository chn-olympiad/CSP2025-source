// club
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
#define N 100005
int t, n, a[N][3], ind[N], num[3];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    t = read<int>(); while (t--) {
        n = read<int>();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = read<int>();
            }
        }
        int ans = 0; num[0] = num[1] = num[2] = 0;
        for (int i = 1; i <= n; i++) {
            int ii = 0;
            for (int j = 1; j < 3; j++) {
                if (a[i][j] > a[i][ii]) ii = j;
            }
            ans += a[i][ii]; ind[i] = ii; num[ii]++;
        }
        bool flag = true;
        for (int j = 0; j < 3; j++) if (num[j] > n / 2) {
            flag = false; break;
        }
        if (flag) {writeln(ans); continue;}
        int ii_ = -1;
        for (int j = 0; j < 3; j++) if (num[j] > n / 2) ii_ = j;
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) if (ind[i] == ii_) {
            int mn = 0x3f3f3f3f;
            for (int j = 0; j < 3; j++) if (j != ii_) {
                mn = min_(mn, a[i][ii_] - a[i][j]);
            }
            q.push(-mn);
        }
        while (num[ii_] > n / 2) {
            ans += q.top(); q.pop(); num[ii_]--;
        }
        writeln(ans);
    }

    return 0;
}
