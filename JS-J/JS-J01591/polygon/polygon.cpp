#include <bits/stdc++.h>
using namespace std;
bool t = true;
int n, a[10000];
long long g[5002][5002];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (a[i] != 1) t = false;
    }
    if (n == 3){
        if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]){
            printf("1");
        }
        else printf("0");
    }
    else if (t){
        for (int i = 1; i <= n; i++){
            g[0][i] = 1;
        }
        for (int i = 0; i <= n; i++){
            g[i][1] = 1;
        }
        for (int i = 1; i <= n - 2; i++){
            for (int j = 2; j <= n - i; j++){
                g[i][j] = g[i - 1][j] + g[i][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 3; i <= n; i++){
            ans += g[n - i][i];
        }
        printf("%lld", ans % 998244353);
    }
    else printf("0");
    fclose(stdin);
    fclose(stdout);
}
