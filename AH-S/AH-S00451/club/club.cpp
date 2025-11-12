#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010][4];
int f[2][5010][5010];
int maxn;
int k;
int n;
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    scanf("%d" , &k);
    while(k--){
        maxn = 0;
        memset(f , 0 , sizeof f);
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 3 ; j++) scanf("%d" , &a[i][j]);
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= n / 2 ; j++){
                for(int k = 0 ; k <= n / 2 ; k++){
                    if(j + k > i) break;
                    if(j + k != i) f[i & 1][j][k] = max(f[i & 1][j][k] , f[i - 1 & 1][j][k] + a[i][1]);
                    if(j != 0) f[i & 1][j][k] = max(f[i & 1][j][k] , f[i - 1 & 1][j - 1][k] + a[i][2]);
                    if(k != 0) f[i & 1][j][k] = max(f[i & 1][j][k] , f[i - 1 & 1][j][k - 1] + a[i][3]);
                    //printf("%d " , f[i & 1][j][k]);
                }
                //printf("\n");
            }
            //printf("\n");
        }
        for(int j = 0 ; j <= n / 2 ; j++){
            for(int k = 0 ; k <= n / 2 ; k++){
                if(n - (j + k) <= n / 2) maxn = max(maxn , f[n & 1][j][k]);
            }
        }
        printf("%d\n" , maxn);
    }
    return 0;
}
