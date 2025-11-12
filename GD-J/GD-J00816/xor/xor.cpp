#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 5e5 + 10, maxa = 1 << 20;

int n, k;
int a[maxn], pre[maxn], sum[maxa], f[maxn];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k), mem(sum, -0x3f), f[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]), pre[i] = pre[i - 1] ^ a[i];
    }
    for (int i = 1; i <= n; i++){
        f[i] = max(f[i - 1], sum[pre[i] ^ k] + 1), sum[pre[i]] = max(sum[pre[i]], f[i]);
    }
    printf("%d", f[n]);

return 0;
}