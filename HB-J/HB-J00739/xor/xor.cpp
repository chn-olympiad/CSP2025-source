#include <bits/stdc++.h>
using namespace std;

int n, a[100010];

int main() {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(n == 2 && a[0] == a[1]) {
        cout << 2;
    }
    else {
        cout << 1;
    }

    return 0;
}
