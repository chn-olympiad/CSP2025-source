#include<bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010];
int suma, sumb, sumc;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T --){
        int n, ans = 0; scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            suma += a[i], sumb += b[i], sumc += c[i];
        }
        int sum_max = max(suma, max(sumb, sumc));
        if(sum_max == suma){
            sort(a + 1, a + 1 + n, cmp); sort(b + 1, b + 1 + n, cmp); sort(c + 1, c + 1 + n, cmp);
            for(int i = 1; i <= n / 2; i ++) ans += a[i];
            for(int i = 1; i <= n / 2; i ++){
                ans += b[i] > c[i] ? b[i] : c[i];
            }
        }
        if(sum_max == sumb){
            sort(a + 1, a + 1 + n, cmp); sort(b + 1, b + 1 + n, cmp); sort(c + 1, c + 1 + n, cmp);
            for(int i = 1; i <= n / 2; i ++) ans += b[i];
            for(int i = 1; i <= n / 2; i ++){
                ans += a[i] > c[i] ? a[i] : c[i];
            }
        }
        if(sum_max == sumc){
            sort(a + 1, a + 1 + n, cmp); sort(b + 1, b + 1 + n, cmp); sort(c + 1, c + 1 + n, cmp);
            for(int i = 1; i <= n / 2; i ++) ans += c[i];
            for(int i = 1; i <= n / 2; i ++){
                ans += a[i] > b[i] ? a[i] : b[i];
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}
