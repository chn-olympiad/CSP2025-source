#include <bits/stdc++.h>
using namespace std;
int l, r, c, n, m, k;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    k = 0;
    for(int i = 1; i <= n; i ++){
        cin >> l >> r >> c;
        k += c;
    }
    cout << k;
    return 0;
}
