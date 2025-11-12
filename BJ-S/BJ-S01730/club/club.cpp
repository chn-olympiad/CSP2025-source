#include <cstdio>
#include <algorithm>
using namespace std;
struct company{
    int num, d;
};
int tmp (int a, int b){
    return a < b;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n, flagA = 0, c[5][100005] = {0}, t[5] = {0};
        long long sum = 0;
        scanf("%d",&n);
        company a[5][100005];
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d",&a[1][i].num,&a[2][i].num,&a[3][i].num);
            a[1][i].d = 1, a[2][i].d = 2, a[3][i].d = 3;
            if(a[2][i].num != 0 || a[3][i].num != 0){
                flagA = 1;
            }
            if (a[1][i].num < a[2][i].num){
                company t = a[1][i];
                a[1][i] = a[2][i];
                a[2][i] = t;
            }
            if (a[2][i].num < a[3][i].num){
                company t = a[2][i];
                a[2][i] = a[3][i];
                a[3][i] = t;
            }
            if (a[1][i].num < a[2][i].num){
                company t = a[1][i];
                a[1][i] = a[2][i];
                a[2][i] = t;
            }
            sum += a[1][i].num;
            c[a[1][i].d][++t[a[1][i].d]] = a[1][i].num - a[2][i].num;
        }
        for (int i = 1; i <= 3; i++){
            sort (c[i] + 1, c[i] + t[i] + 1, tmp);
        }
        for (int i = 1; i <= 3; i++){
            for (int j = 1; j <= t[i] - (n / 2); j++){
                sum -= c[i][j];
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
