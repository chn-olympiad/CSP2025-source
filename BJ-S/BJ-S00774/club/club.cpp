#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
ll T, n, ans;
ll a[100010], b[100010], c[100010];
bool f;
ll ma, mb, mc;
bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T --){
        ma = 0;
        mb = 0;
        mc = 0;
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i ++){
            cin >> a[i] >> b[i] >> c[i];
            if(b[i] != 0 || c[i] != 0){
                f = true;
            }
        }
        if(f){
            for(int i = 1;i <= n;i ++){
                if(max(a[i], max(b[i], c[i])) == a[i]){
                    if(ma < n / 2){
                        ans += a[i];
                        ma ++;
                    }
                    else{
                        ans += max(b[i], c[i]);
                        if(max(b[i], c[i]) == b[i]){
                            mb ++;
                            if(mb > n / 2){
                                mb --;
                                ans -= b[i];
                                ans += c[i];
                                mc ++;
                            }
                        }
                        if(max(b[i], c[i]) == c[i]){
                            mc ++;
                            if(mc > n / 2){
                                mc --;
                                ans -= c[i];
                                ans += b[i];
                                mb ++;
                            }
                        }
                    }
                }
                if(max(a[i], max(b[i], c[i])) == b[i]){
                    if(mb < n / 2){
                        ans += b[i];
                        mb ++;
                    }
                    else{
                        ans += max(a[i], c[i]);
                        if(max(a[i], c[i]) == a[i]){
                            ma ++;
                            if(ma > n / 2){
                                ma --;
                                ans -= a[i];
                                ans += c[i];
                                mc ++;
                            }
                        }
                        if(max(a[i], c[i]) == c[i]){
                            mc ++;
                            if(mc > n / 2){
                                mc --;
                                ans -= c[i];
                                ans += a[i];
                                ma ++;
                            }
                        }
                    }
                }
                if(max(a[i], max(b[i], c[i])) == c[i]){
                    if(mc < n / 2){
                        ans += c[i];
                        mc ++;
                    }
                    else{
                        ans += max(a[i], b[i]);
                        if(max(a[i], b[i]) == a[i]){
                            ma ++;
                            if(ma > n / 2){
                                ma --;
                                ans -= a[i];
                                ans += b[i];
                                mb ++;
                            }
                        }
                        if(max(a[i], b[i]) == b[i]){
                            mb ++;
                            if(mc > n / 2){
                                mb --;
                                ans -= b[i];
                                ans += a[i];
                                ma ++;
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
        }
        else{
            sort(a + 1, a + 1 + n, cmp);
            for(int i = 1;i <= n / 2;i ++){
                ans += a[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
