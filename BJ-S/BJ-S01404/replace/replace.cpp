// replace
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
#define N 105
#define M 205
int n, q;
string s1[N], s2[N];
string t1, t2;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    n = read<int>(); q = read<int>();
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }
    while (q--) {
        cin >> t1 >> t2;
        int ans = 0;
        int n1 = t1.length(), n2 = t2.length();
        if (n1 != n2) {writeln(0); continue;}
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n1 - (int)s1[i].length(); j++) {
                bool flag = true;
                for (int k = j; k < j + (int)s1[i].length(); k++) {
                    if (s1[i][k - j] != t1[k] || s2[i][k - j] != t2[k]) {
                        flag = false; break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < j; k++) {
                    if (t1[k] != t2[k]) {
                        flag = false; break;
                    }
                }
                if (!flag) continue;
                for (int k = j + (int)s1[i].length(); k < n1; k++) {
                    if (t1[k] != t2[k]) {
                        flag = false; break;
                    }
                }
                if (!flag) continue;
                ans++;
            }
        }
        writeln(ans);
    }

    return 0;
}
