#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    if (n <= 2){
        cout << 0;
    }else if (n == 3){
        sort(a, a+n);
        if (a[0]+a[1]+a[2] > 2*a[2]){
            cout << 1;
        }else{
            cout << 0;
        }
    }else cout << 1;
    return 0;
}
