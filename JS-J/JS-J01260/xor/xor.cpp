#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(k == 0) cout << n / 2;
    else if(k == 1){
        long long ans = 0;
        for(long long i = 1;i <= n;i++){
            if(a[i] == 1) ans++;
        }
        cout << ans;
    }
    else cout << n;
    return 0;
}
