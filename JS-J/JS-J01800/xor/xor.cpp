#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[500005], ans, k, n, lst;
bool f = 1;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1) f = 0;
    }
    if (f){
        if (k == 1){
            cout << n;
        }
        else{
            cout << n / 2;
        }
        return 0;
    }
    for (ll i = 1; i <= n; i++){
        ll x = 0;
        for (ll j = i; j > lst; j--){
            x ^= a[j];
            if (x == k){
                lst = j;
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
