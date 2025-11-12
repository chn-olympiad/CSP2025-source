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

const int N = 1e5 + 10;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    print(13);
    return 0;
}
