#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans, sum;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        ans ^= a[i];
        if(ans == k){
            sum++;
            ans = 0;
        }
    }
    cout << sum;
    return 0;
}
