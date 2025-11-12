#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxn = -1,res = 1;
long long cnt = 1,ans = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n == 3){
        for (int i = 1;i <= n;i++){
            cnt += a[i];
            maxn = max(maxn,a[i]);
        }
        if (cnt > (maxn * 2)) cout << 1;
        else cout << 0;
        return 0;
    }else if(n < 3){
        cout << 0;
        return 0;
    }else{
        for (int i = 4;i <= n;i++){
            for (int j = 0;j < i;j++){
                res *= (n - j);
            }
            ans += res % 998244353;
        }
        cout << ans;
        return 0;
}
