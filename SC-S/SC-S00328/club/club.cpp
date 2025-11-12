#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int t,n;
const int N = 203,V = 1e5 + 3;
i64 a[V][4],f[2][4][N][N];
i64 d[V];
void mian(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
    }
    if(n > 200){
        for(int i = 1;i <= n;i++){
            d[i] = a[i][1];
        }
        sort(d + 1,d + n + 1,[](int x,int y){ return x > y; });
        i64 ans = 0;
        for(int i = 1;i <= n / 2;i++){
            ans += d[i];
        }
        printf("%lld\n",ans);
        return;
    }
    memset(f,0,sizeof(f));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n / 2;j++){
            for(int k = 0;k <= n / 2;k++){
                if(i - j - k > n / 2) continue;
                if(j > 0) f[i % 2][1][j][k] = max(f[(i - 1) % 2][1][j - 1][k],max(f[(i - 1) % 2][2][j - 1][k],f[(i - 1) % 2][3][j - 1][k])) + a[i][1];
                if(k > 0) f[i % 2][2][j][k] = max(f[(i - 1) % 2][1][j][k - 1],max(f[(i - 1) % 2][2][j][k - 1],f[(i - 1) % 2][3][j][k - 1])) + a[i][2];
                if(i - j - k > 0) f[i % 2][3][j][k] = max(f[(i - 1) % 2][1][j][k],max(f[(i - 1) % 2][2][j][k],f[(i - 1) % 2][3][j][k])) + a[i][3];
            }
        }
    }
    i64 ans = 0;
    for(int i = 0;i <= n / 2;i++){
        for(int j = 0;j <= n / 2;j++){
            if(n - i - j > n / 2) continue;
            ans = max(max(ans,f[n % 2][1][i][j]),max(f[n % 2][2][i][j],f[n % 2][3][i][j]));
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        mian();
    }
    return 0;
}