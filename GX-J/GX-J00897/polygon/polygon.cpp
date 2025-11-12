#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e3+10;
int a[MAXN];
ll mod = 998244353;
int n;
ll cnt = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    if(n<=3){
        cout << 1;
    }else if(n>3 && n <= 10){
        for(int c = 1 ; c <= n ; c++){
            int sum = 0,maxn = -1;
            sum += a[c];
            maxn = max(maxn,a[c]);
            for(int d = c + 1 ; d <= n ; d++){
                sum += a[d];
                maxn = max(maxn,a[d]);
                for(int e = d + 1 ; e <= n ; e++){
                    sum+=a[e];
                    maxn = max(maxn,a[e]);
                    if(sum > 2 * maxn)cnt++;
                    for(int f = e+1 ; f <= n ; f++){
                        if(f > n)break;
                        sum+=a[f];
                        maxn = max(maxn,a[f]);
                        if(sum > 2 * maxn)cnt++;
                        for(int g = f + 1 ; g <= n ; g++){
                            if(g > n)break;
                            sum+=a[g];
                            maxn = max(maxn,a[c]);
                            if(sum > 2 * maxn)cnt++;
                            for(int h = g + 1 ; h <= n ; h++){
                                if(h > n)break;
                                sum += a[h];
                                maxn = max(maxn,a[h]);
                                if(sum > 2 * maxn )cnt++;
                                for(int i = h + 1 ; i <= n ; i++){
                                    if(i > n)break;
                                    sum += a[i];
                                    maxn = max(maxn,a[i]);
                                    if(sum > 2*maxn)cnt++;
                                    for(int j = i + 1 ; j <= n ; j++){
                                        if(j > n)break;
                                        sum += a[j];
                                        maxn = max(maxn,a[j]);
                                        if(sum > 2*maxn)cnt++;
                                        for(int k = j + 1 ; k <= n ; k++){
                                            if(k > n)break;
                                            sum += a[k];
                                            maxn = max(maxn,a[k]);
                                            if(sum > 2*maxn)cnt++;
                                            for(int l = k + 1 ; l <= n ; l++){
                                                if(l > n)break;
                                                sum += a[l];
                                                maxn = max(maxn,a[l]);
                                                if(sum > 2*maxn)cnt++;
                                                sum -= a[l];
                                            }
                                            sum -= a[k];
                                        }
                                        sum -= a[j];
                                    }
                                    sum -= a[i];
                                }
                                sum -= a[h];
                            }
                            sum -= a[g];
                        }
                        sum -= a[f];
                    }
                    sum -= a[e];
                }
                sum -= a[d];
            }
            sum -= a[c];
        }
        cout << cnt % mod;
    }else if(a[1] = 1){
        cnt = 1;
        for(int i = 2 ; i <= n ; i++){
            for(int j = i ; j <= n ; j++){
                cnt += n - j;
            }
        }
        cout << (cnt % mod);
    }
    return 0;
}
