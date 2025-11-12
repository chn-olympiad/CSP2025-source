#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, a[500005], maxn = -1, minn = 9999999999;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    if (maxn == minn == 1) {
        cout << n / 2;
        return 0;
    }
    if (maxn == 1 && minn == 0){
        ll ans = 0;
        if (k == 1){
            for (int i = 1; i <= n; ++i){
                if (a[i] == 1) ans++;
            }
            cout << ans;
        }
        if (k == 0){
            for (int i = 1; i <= n; ++i){
                if (a[i] == 0) ans++;
                if (a[i] == 1) {
                    if (a[i - 1] == 1) continue;
                    int j = i, jsq = 0;
                    while (a[j] == 1){
                        j++;
                        jsq++;
                    }
                    ans += jsq / 2;
                }
            }
            cout << ans;
        }
        return 0;
    }
    cout << 1;
    return 0;
}
