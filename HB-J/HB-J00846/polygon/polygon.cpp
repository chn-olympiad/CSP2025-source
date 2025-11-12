#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005], maxn[5005], sum[5005], f[5005];
int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        maxn[i] = max(maxn[i - 1], a[i]);
    }
    for(i = 1;i <= n;i++){
        for(j = i;j <= n;j++){
            int s = sum[j] - sum[i - 1], nmax = -1;
            for(int k = i;k <= j;k++) nmax = max(nmax, a[k]);
            if(nmax * 2 < s) f[i] = max(f[i], f[i - 1]) + 1;
        }
    }
    printf("%d", f[n]);
    return 0;
}
