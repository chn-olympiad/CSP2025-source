#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int m = a[1] + a[2] + a[3];
    int mx = 0;
    for (int i = 1;i <= n;i++){
        if (a[i] > mx) mx = a[i];
    }
    if (m > (2 * mx)) cout << 1;
    else cout << 0;
    return 0;
}
