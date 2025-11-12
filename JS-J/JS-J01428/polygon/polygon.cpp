#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
#define maxn 5005

int n;
int a[maxn];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    if(n < 3){
        puts("0");
        return 0;
    }
    if(n == 3){
        scanf("%d%d%d", &a[1], &a[2], &a[3]);
        if(a[1] + a[2] <= a[3] || a[1] + a[3] <= a[2] || a[2] + a[3] <= a[1]){
            puts("0");
            return 0;
        }else{
            puts("1");
            return 0;
        }
    }
    for(int i = 4; i <= n; i++){
        scanf("%d", &a[i]);
    }

    return 0;
}
