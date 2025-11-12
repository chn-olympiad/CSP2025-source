#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 5e5 + 10, V = 2e6 + 10;
int mxid[V], s[N], a[N], n, k, las[N], f[N];
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    for (int i = 1; i < V; i++) mxid[i] = -1;
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        s[i] = s[i - 1] ^ a[i];
    }
    for (int i = 1; i <= n; i++) {
        las[i] = mxid[s[i] ^ k] + 1;
        mxid[s[i]] = i;
    }
    
    // for (int i = 1; i <= n; i++) printf ("%d ", las[i]);
    // printf ("\n");
    
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (las[i]) f[i] = std::max (f[i], f[las[i] - 1] + 1);
    }
    printf ("%d\n", f[n]);
    fclose (stdin);
    fclose (stdout);
    return 0;
}