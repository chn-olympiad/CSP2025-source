#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
ll n;
ll a[N], s[N], used[N], l, r, ans;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;

    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n < 3){//tepan
        cout << 0 << "\n";
        return 0;
    }

    stable_sort(a + 1, a + 1 + n);
    if(n == 3){//tepan
        if(a[1] + a[2] + a[3] > a[3] * 2){
            cout << 1 << "\n";
            return 0;
        }
        cout << 0 << "\n";
        return 0;
    }
    for(ll k = 3; k <= n; k++){
        for(ll i = 1; i <= n; i++){
            if(i != k && used[i] != 1){
                ll t = a[k] - a[i];
                for(ll j = i + 1; j <= n; j++){
                    if(a[j] > t && used[j] != 1 && j != k) ans++;
                }
            }
        }
        used[k] = 1;
    }
    cout << ans + 2 << "\n";
    return 0;
}
