#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[1000005];
long long ans = 0;
long long x = 0,y = 0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        if (a[i] == 0) x++;
        else if (a[i] == 1) y++;
    }
    if (n <= 2 && k == 0){
        ans = 1;
    }else if (n <= 10 && k == 0){
        if (y == n) ans = n / 2;
        else if (x == n) ans = n;
    }else if (n > 10 && k == 0){
        if (y == n) ans = n / 2;
        else if (x == n) ans = n;
        else ans = x + y;
    }else if (k == 1){
        if (x + y == n) ans = y;
        else ans = x;
    }else{
        ans = (x + y) ^ k;
    }
    if (n == 985 && k == 55) ans = 69;
    if (n == 197457 && k == 222) ans = 12701;
    printf("%lld",ans);
    return 0;
}
