#include <bits/stdc++.h>
using namespace std;
int a[500007];
int mx=0, n, k;
void d(int ct, int sum){
    if(ct>n){
        mx=max(sum, mx);
        //puts("L");
    }
    for(int i=1; i<=n-ct+1; ++i){
        int m=a[ct+i-1]^a[ct-1];
        if(ct==1){
            m=a[ct+i-1];
        }
        if(m==k){
            d(ct+i, sum+1);
            //puts("d");
        }
        d(ct+i, sum);
    }
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i){
        scanf("%d", a+i);
        if(i>1){
            a[i]^=a[i-1];
        }
    }
    d(1, 0);
    printf("%d", mx);
}
