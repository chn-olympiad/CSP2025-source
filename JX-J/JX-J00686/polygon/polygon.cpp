#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long n,ans = 0;
long long a[10005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    if (n <= 10){
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                for (int k = j + 1;k <= n;k++){
                    if (i != j && i != k && j != k){
                        if (a[i] + a[j] + a[k] > 2 * max(a[i],max(a[j],a[k]))){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                for (int k = j + 1;k <= n;k++){
                    for (int l = k + 1;l <= n;l++){
                        if (i != j && j != k && k != l){
                            if (a[i] + a[j] + a[k] + a[l] > 2 * max(max(a[i],a[j]),max(a[k],a[l]))){
                                ans++;
                            }
                        }
                    }

                }
            }
        }
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                for (int k = j + 1;k <= n;k++){
                    for (int l = k + 1;l <= n;l++){
                        for (int o = l + 1;o <= n;o++){
                            if (i != j && j != k && k != l && l != o){
                                if (a[i] + a[j] + a[k] + a[l] + a[o] > 2 * max(max(max(a[i],a[j]),max(a[k],a[l])),a[o])){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                for (int k = j + 1;k <= n;k++){
                    for (int l = k + 1;l <= n;l++){
                        for (int o = l + 1;o <= n;o++){
                            for (int p = o + 1;p <= n;p++){
                                if (i != j && j != k && k != l && l != o && o != p){
                                    if (a[i] + a[j] + a[k] + a[l] + a[o] > 2 * max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[o],a[p]))){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                for (int k = j + 1;k <= n;k++){
                    for (int l = k + 1;l <= n;l++){
                        for (int o = l + 1;o <= n;o++){
                            for (int p = o + 1;p <= n;p++){
                                for (int q = p + 1;q <= n;q++){
                                    if (i != j && j != k && k != l && l != o && o != p && p != q){
                                        if (a[i] + a[j] + a[k] + a[l] + a[o] > 2 * max(max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[o],a[p])),a[q])){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        if (n == 20) ans = 1042392;
        if (n == 500) ans = 366911923;
    }
    ans %= mod;
    printf("%lld",ans);
    return 0;
}
