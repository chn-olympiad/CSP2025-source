#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("xor.in", "r", stdin);
        freopen("xor.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
const int N = 5e5 + 5;
const int V = 2e6 + 5;
int n, k, a[N], f[N];
int ch[V][2], idx[V], cnt;
void insert (int x, int id) {
    int u = 0;
    for (int i = 0; i < 20; i++) {
        int c = (bool)((1 << i) & x);
        if (!ch[u][c]) ch[u][c] = ++cnt;
        u = ch[u][c];
    }
    idx[u] = id;
}
int query (int x) {
    int u = 0;
    for (int i = 0; i < 20; i++) {
        int c = (bool)((1 << i) & x);
        if (!ch[u][c]) return -1;
        u = ch[u][c];
    }
    return idx[u];
}
int main () {
    scanf("%d%d", &n, &k);
    insert(0, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
        int q = query(a[i] ^ k);
        // printf("query(%d):%d\n", a[i] ^ k, q);
        f[i] = f[i - 1];
        if (q != -1) f[i] = max(f[i], f[q] + 1);
        insert(a[i], i);
    }
    printf("%d\n", f[n]);
    return 0; 
}