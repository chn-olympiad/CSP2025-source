#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, a[5005];
int s, m;
int tmp;
int ans;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    if(n==3) {
        if(a[1]+a[2]+a[3]>2*max(a[1], max(a[2], a[3]))) {
            printf("1");
        }
        else {
            printf("0");
        }
        return 0;
    }
    for(i=3; i<=n; i++) {
            tmp=1;
        for(j=n; j>n-i; j--) {
            tmp*=j;
            tmp/=n-j+1;
            tmp%=998244353;
        }
        ans+=tmp;
    }
    printf("%d", ans);
    return 0;
}
