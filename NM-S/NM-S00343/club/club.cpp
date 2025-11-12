#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int n, t, m;
    int a, b, c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a >> b >> c;
        }
    }
    if (n / 2 < t) {
        m = a + b + c;
        cout << m;
    }
    //for (int i = 0; i >= n; i--) {
        //cout << i;
    //}
    return 0;
}
