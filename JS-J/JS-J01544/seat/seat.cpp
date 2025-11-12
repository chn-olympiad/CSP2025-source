#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m, cur, l = 1, c = 1, dir = 1;
    cin >> n >> m;

    for (int i = 1; i <= n * m; ++i) cin >> a[i];
    cur = a[1];
    sort(a + 1, a + 1 + n * m);
    reverse(a + 1, a + 1 + n * m);

    for (int i = 1; i <= n * m; ++i){
        if (a[i] == cur){
            cout << c << " " << l;
            break;
        }
        if (dir > 0 && l < n) l += dir;
        else if (dir < 0 && l > 1) l += dir;
        else if (dir > 0) c += 1, dir = -1;
        else c += 1, dir = 1;
    }
    return 0;
}
