#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXM (1<<20)

int n, k, ct; int buk[MAXM], f[MAXN], a[MAXN];

signed main(){
    freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k; for (int i(1); i<=n; ++i) cin >> a[i], a[i] ^= a[i-1];
    memset(buk, -1, sizeof(buk)); buk[0] = 0;
    for (int i(1); i<=n; ++i){
        f[i] = f[i-1]; if (~buk[a[i]^k]) f[i] = max(f[i], f[buk[a[i]^k]]+1); buk[a[i]] = i;
    }
    cout << *max_element(f, f+n+1);

    return 0;
}