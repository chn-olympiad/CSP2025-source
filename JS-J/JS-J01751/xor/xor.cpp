#include <bits/stdc++.h>
using namespace std;
int n0, n1, n, k;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1) n1++;
        else n0++;
    }
    if (k == 1){
        cout << n1;
        return 0;
    }
    int ans = n0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            if (a[i+1] == 1){
                ans++;
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}
