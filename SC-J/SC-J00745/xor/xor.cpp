#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long

const int N = 5e5 + 10, M = 3e6 + 10;
int n, k, cnt, sum[N], f[N], ppp[N];

struct Trie {

    char tr[N][11];
    int tag[M], tot;

    void clear() {
        memset(tag, -1, sizeof tag);
        return ;
    }

    void insert(std :: string s, int pos) {
        int u = 0;
        for (auto c : s) {
            int bit = c - '0';
            if (!tr[u][bit]) tr[u][bit] = ++ tot;
            u = tr[u][bit];
        }
        tag[u] = pos;
        return ;
    }

    int query(std :: string s) {
        int u = 0;
        for (auto c : s) {
            int bit = c - '0';
            if (!tr[u][bit]) return -1;
            u = tr[u][bit];
        }
        return tag[u];
    }

} T;

std :: string split(int n) {
    if (n == 0) return "0";
    std :: string s = "";
    while (n) {
        s += n % 10 + '0';
        n /= 10;
    }
    std :: reverse(s.begin(), s.end());
    return s;
}

int read() {
    int a = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') a = (a << 3) + (a << 1) + c - '0', c = getchar();
    return a;
}

signed main() {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    T.clear();
    n = read(), k = read();
    T.insert(split(0), 0);
    for (int i = 1; i <= n; i ++) {
        int a = read();
        sum[i] = (sum[i - 1] ^ a), T.insert(split(sum[i]), i);
        int j = T.query(split(sum[i] ^ k));
        f[i] = f[i - 1];
        if (j >= 1 && !(a != 0 && j == i)) f[i] = std :: max(f[i], f[j] + 1);
        if (j == 0) f[i] = std :: max(f[i], 1ll);
    }
    
    printf("%lld\n", f[n] - cnt);

    return 0;
}