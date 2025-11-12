#include <cstdio>
#include <algorithm>
#define uint unsigned long long
#define sint long long
const int maxn = 2e6 + 5;
int a[maxn], x[maxn];
int p[maxn];
struct seg{
    int l, r;
} s[maxn];
inline bool operator < (seg u, seg v){
    if(u.r ^ v.r) return u.r < v.r;
    return u.l > v.l; 
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) x[i] = x[i - 1] ^ a[i];
    for(int i = 1; i <= n; i++){
        p[i] = i;
        while(p[i] <= n && (x[p[i]] ^ x[i - 1] ^ k)) p[i] ++;
    }
    for(int i = 1; i <= n; i++) s[i].l = i, s[i].r = p[i];
    std::sort(s + 1, s + n + 1);
    int t = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(t < s[i].l && s[i].r <= n) t = s[i].r, cnt ++;
    }
    printf("%d\n", cnt);
    return 0;
}