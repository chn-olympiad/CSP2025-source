#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int f[110][110][1010][4];
int a[5010];
int ans;
int n;
int dfs(int i , int maxn , int tot , int cnt){
    if(cnt >= 3) cnt = 3;
    if(f[i][maxn][tot][cnt] != 0) return f[i][maxn][tot][cnt];
    if(i > n){
        if(maxn * 2 < tot && cnt >= 3) return 1;
        return 0;
    }
    f[i][maxn][tot][cnt] += dfs(i + 1 , maxn , tot , cnt);
    f[i][maxn][tot][cnt] %= mod;
    f[i][maxn][tot][cnt] += dfs(i + 1 , max(maxn , a[i]) , tot + a[i] , cnt + 1);
    f[i][maxn][tot][cnt] %= mod;
    return f[i][maxn][tot][cnt];
}
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++) scanf("%d" , &a[i]);
    dfs(1 , 0 , 0 , 0);
    printf("%d" , f[1][0][0][0]);
    return 0;
}
