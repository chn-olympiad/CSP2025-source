#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[n],ma_l=0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        ma_l=max(a[i],ma_l);
    }
    if (n <= 3) {
        if (ma_l*2 < a[0]+a[1]+a[2]) {
            cout << 1 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
}
