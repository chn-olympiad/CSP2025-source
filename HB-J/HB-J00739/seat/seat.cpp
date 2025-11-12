#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, a[110];

bool cmp(int x, int y) {

    return x > y;

}

int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n*m; i++) {
        cin >> a[i];
    }
    x = a[0];
    sort(a, a+(n*m), cmp);
    for(int i=0; i<n*m; i++) {
        if(a[i] == x) {
            y = i+1;
            break;
        }
    }
    if(y % n == 0) {
        if(((y/n)) % 2) {
            cout << y / n << " " << y-(((y/n)-1)*n);
        }
        else {
            cout << y / n << " " << n-(y-(((y/n)-1)*n));
        }
    }
    else {
        if(((y/n)+1) % 2) {
            cout << (y/n)+1 << " " << y-((y/n)*n);
        }
        else {
            cout << (y/n)+1 << " " << n-(y-((y/n)*n))+1;
        }
    }

    return 0;
}
