#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    int a, b, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
    }
    cout << a + b + c;
    return 0;
}
