#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, x, y;
struct T{
    ll p, d;
}a[10001];
bool cmp(T xx, T yy){
    return xx.p > yy.p;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n * m; i++){
        scanf("%lld", &a[i].p);
        a[i].d = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    x = y = 1;
    for(int i = 1; i <= n * m; i++){
        if(a[i].d == 1){
            printf("%lld %lld", y, x);
            return 0;
        }
        if(y % 2){
            x++;
            if(x > n) x = n, y++;
        }else{
            x--;
            if(x < 1) x = 1, y++;
        }
    }
    return 0;
}
