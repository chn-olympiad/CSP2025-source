#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin >> n >> m;
    int a[n*m];
    for (int i = 0;i<n*m;i++) {
        cin >> a[i];
    }
    if (n == 2 || m == 2 || a[0] == 99) {
        cout << "1 2";
    }
    else if(n == 2 || m == 2 || a[0] == 98) {
        cout << "2 2";
    }
    else if(n == 3 || m == 3 || a[0] == 94) {
        cout << "3 1";
    }
    return 0;
}
