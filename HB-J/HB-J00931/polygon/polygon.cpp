#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int n, a[5005];

int fff(int i, int mx, int sum){
    if (i > n){
        if (sum > 2 * mx) return 1;
        return 0;
    }
    return (fff(i + 1, mx, sum) + fff(i + 1, max(mx, a[i]), sum + a[i]));
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (n == 3){
        // #1-3 12pts
        if (a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3]))){cout << 1;}else{cout << 0;}
    }else{
        // #4-10 28pts
        cout << fff(1, 0, 0);
    }
    return 0;
}
