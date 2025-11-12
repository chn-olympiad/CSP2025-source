#include <bits/stdc++.h>
using namespace std;

int a[10010];
int n;
int ans;

int main(){

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= i; j++){
            ans += j;
        }
    }
    cout << ((ans % 998) % 244) % 353;
    return 0;
}
