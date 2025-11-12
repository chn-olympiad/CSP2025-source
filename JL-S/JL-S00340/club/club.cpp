#define dps 799
#define I dryer
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200500;
int a[N],b[N],c[N];
int f[211][211][211];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%lld", &T);
    while(T --){
        int n; scanf("%lld", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld%lld", &a[i],&b[i],&c[i]);
        }
        if(n <= 200){
            for(int i = 1; i <= n; ++ i){
                for(int j = 0; j <= min(i - 1,n / 2); ++ j){
                    for(int k = 0; k <= min(i - j - 1, n / 2); ++ k){
                        int l = i - j - k - 1;
                        if(j + 1 <= n/2 && k <= n / 2 && l <= n / 2) f[i][j+1][k] = max(f[i][j+1][k], f[i-1][j][k] + a[i]);
                        if(k + 1 <= n/2 && j <= n / 2 && l <= n / 2) f[i][j][k+1] = max(f[i][j][k + 1], f[i-1][j][k] + b[i]);
                        if(l + 1 <= n / 2 && k <= n / 2 && j <= n / 2) f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + c[i]);
                    }
                }
            }
            int ans = 0;
  /*          for(int i = 1; i <= n; ++ i) {
                for(int j = 0; j <= n; ++ j){
                    for(int k = 0; k <= n; ++ k){
                        cout << f[i][j][k] << ' ';
                    }
                    cout << endl;
                }
                cout << endl;
            } */
            for(int i = 0; i <= n; ++ i){
                for(int j = 0; j <= n; ++ j){
                    int k = n - i - j;
                    if(k <= n / 2 && j <= n / 2 && i <= n / 2) ans = max(ans, f[n][i][j]);
                }
            }
            cout << ans << endl;
            memset(f,0,sizeof f);
        }
        else{
            int ans = 0;
            for(int i = 1; i <= n; ++ i){
                ans += a[i];
            }
            for(int i = 1; i <= n; ++ i){
                c[i] = b[i] - a[i];
            }
            sort(c + 1, c + 1 + n);
            reverse(c + 1, c + 1 + n);
            for(int i = 1; i <= n / 2; ++ i) ans += c[i];
            cout << ans << endl;
        }
    }
}
