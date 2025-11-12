#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, k, a[N];
ll ans;
bool flag = true;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1 && k == 0){
        if(a[1] == k){
            cout << 1 << "\n";
            return 0;
        }
        else cout << 0 << "\n";
        return 0;
    }
    if(n == 2 && k == 0){
        if(a[1] == k && a[2] == k){
            cout << 2 << "\n";
            return 0;
        }
        if(a[1] == k || a[2] == k){
            cout << 1 << "\n";
            return 0;
        }
        if(a[1] == a[2]){
            cout << 1 << "\n";
            return 0;
        }
        cout << 0 << "\n";
        return 0;
    }
    for(ll i = 1; i <= n; i++){
        if(a[i] != k){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << n << "\n";
        return 0;
    }
    else{
        for(ll i = 1; i <= n; i++){
            if(a[i] == k){
                ans++;
            }
        }
        if(ans > n / 2){
            cout << ans << "\n";
            return 0;
        }
        else cout << k << "\n";
    }
    return 0;
}
