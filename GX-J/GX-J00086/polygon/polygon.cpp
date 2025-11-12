#include<bits/stdc++.h>
using namespace std;
int n, a[5005], cnt, maxn = -100;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if(n < 3){cout << 0; return 0;}
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxn) maxn = a[i];
    }
    int he = a[0] + a[1] + a[2];
    maxn *= 2;
    if(he > maxn) cout << 1;
    else cout << 0;
    return 0;
}
