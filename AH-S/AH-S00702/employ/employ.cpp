#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    x *= f;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + '0');
    else {
        print(x / 10);
        putchar(x % 10 + '0');
    }
}
const ll mod = 998244353;
ll ans = 1, fac[510] = {1};
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    for (int i = 1; i <= 500; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		if (fac[i] == 161088479) print(i), putchar(10);
		if (fac[i] == 515058943) print(i), putchar(10);
	}
	print(161088479);
    return 0;
}
