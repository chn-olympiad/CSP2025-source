#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5002;
const ll MOD = 998244353;
int n;
int a[N];
map<int, ll> f[N][4];  //add == k,  m , count

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    ll ans = 0;
    if (n > 30){
        int t = 0, s = 1;
        for (int i = 1; i <= n; i++, t ^= 1){
            s = t ^ 1;
            //printf("%d\n",i);

            for (int e = 1; e <= 3; e++)
                f[s][e] = f[t][e];
            f[s][1][a[i]]++;
            for (auto it : f[t][1]){
                f[s][2][it.first+a[i]] = (f[s][2][it.first+a[i]] + it.second) % MOD;
            }
            for (auto it : f[t][2]){
                if (it.first > a[i])
                    ans = (ans + it.second) % MOD;
                f[s][3][it.first+a[i]] = (f[s][3][it.first+a[i]] + it.second) % MOD;
            }
            for (auto it : f[t][3]){
                if (it.first > a[i])
                    ans = (ans + it.second) % MOD;
                f[s][3][it.first+a[i]] = (f[s][3][it.first+a[i]] + it.second) % MOD;
            }
        }
        /*for (int e = 1; e <= 3; e++){
                printf("\n%d---------\n",e);
                for (auto it : f[s][e])
                    printf("%d %lld\n",it.first,it.second);
        }*/
        /*for (int i = 1; i <= n; i++){
            for (auto it : f[s][3])
                if (it.first > a[i]*2)
                    ans = (ans + it.second) % MOD;
        }*/
        printf("%lld",ans);

    }
    else{
        for (int i = 1; i <= n; i++){
            //printf("%d\n",i);
            f[i][1][a[i]] = 1;
            for (int j = 1; j <= i-1; j++){
                for (auto it : f[j][1]){
                    f[i][2][it.first+a[i]] = (f[i][2][it.first+a[i]] + it.second) % MOD;
                }
                for (auto it : f[j][2]){
                    //if (it.first > a[i])
                    f[i][3][it.first+a[i]] = (f[i][3][it.first+a[i]] + it.second) % MOD;
                }
                for (auto it : f[j][3]){
                    //if (it.first > a[i])
                    f[i][3][it.first+a[i]] = (f[i][3][it.first+a[i]] + it.second) % MOD;
                }
            }

        }
        /*for (int i = 1; i <= n; i++){
            for (int e = 1; e <= 3; e++){
                printf("\n%d %d--------\n",i,e);
                for (auto it : f[i][e])
                    printf("%d %lld\n",it.first,it.second);
            }
        }*/
        for (int i = 1; i <= n; i++){
            for (auto it : f[i][3])
                if (it.first > a[i]*2)
                    ans = (ans + it.second) % MOD;
        }
        printf("%lld",ans);
    }

    return 0;
}
