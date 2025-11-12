#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 5e3 + 1;
int num[maxn];

int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n;
    ll cnt = 0;
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; i += 1){
        scanf("%d" , &num[i]);
    }
    for (int i = 3 ; i <= n ; i += 1){
        if (i == 3){
            for (int j = 1 ; j <= n ; j += 1){
                for (int k = j + 1 ; k <= n ; k += 1){
                    for (int m = k + 1 ; m <= n ; m += 1){
                        int a = num[j] , b = num[k] , c = num[m];
                        int tmp = a + b + c;
                        if (a * 2 < tmp && b * 2 < tmp && c * 2 < tmp){
                            cnt += 1;
                        }
                    }
                }
            }
        }
        if (i == 4){
            for (int p = 1 ; p <= n ; p += 1){
                for (int j = p + 1 ; j <= n ; j += 1){
                    for (int k = j + 1 ; k <= n ; k += 1){
                        for (int m = k + 1 ; m <= n ; m += 1){
                            int a = num[j] , b = num[k] , c = num[m] , d = num[p];
                            int tmp = a + b + c + d;
                            if (a * 2 < tmp && b * 2 < tmp && c * 2 < tmp && d * 2 < tmp){
                                cnt += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    cnt %= 998244353;
    printf("%lld" , cnt);
    return 0;
}
