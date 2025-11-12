#include <bits/stdc++.h>

using namespace std;

int T , n , a[100001][3] , ans = 0 , sum1 = 0 , sum2 = 0 , sum3 = 0 , c[100001] , l = 0;

int main() {
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    scanf("%d" , &T);
    for(int i=1;i<=T;i++) {
        ans = sum1 = sum2 = sum3 = 0;
        scanf("%d" , &n);
        for(int j=1;j<=n;j++) {
            scanf("%d%d%d" , &a[j][0] , &a[j][1] , &a[j][2]);
            if(a[j][0] >= a[j][1] && a[j][0] >= a[j][2]) {
                sum1++;
                ans += a[j][0];
            }
            else {
                if(a[j][1] >= a[j][0] && a[j][1] >= a[j][2]) {
                    sum2++;
                    ans += a[j][1];
                }
                else {
                    sum3++;
                    ans += a[j][2];
                }
            }
        }
        if(sum1 > n / 2) {
            for(int j=1;j<=n;j++) {
                if(a[j][0] >= a[j][1] && a[j][0] >= a[j][2]) {
                    c[++l] = a[j][0] - max(a[j][1] , a[j][2]);
                }
            }
        }
        if(sum2 > n / 2) {
            for(int j=1;j<=n;j++) {
                if(a[j][1] >= a[j][0] && a[j][1] >= a[j][2]) {
                    c[++l] = a[j][1] - max(a[j][0] , a[j][2]);
                }
            }
        }
        if(sum3 > n / 2) {
            for(int j=1;j<=n;j++) {
                if(a[j][2] >= a[j][1] && a[j][2] >= a[j][0]) {
                    c[++l] = a[j][2] - max(a[j][1] , a[j][0]);
                }
            }
        }
        sort(c + 1 , c + l + 1);
        for(int j=1;j<=max(sum1 , max(sum2 , sum3))-n/2;j++) {
            ans -= c[j];
        }
        printf("%d" , ans);
    }
    return 0;
}
