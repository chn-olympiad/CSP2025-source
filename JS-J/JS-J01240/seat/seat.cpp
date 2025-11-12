#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
    int id;
    int v;
}a[105];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, pos=0;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++){
        cin >> a[i].v;
        a[i].id = i;
    }
    sort (a, a + n * m, [](Node x, Node y){
        return x.v > y.v;
    });
    for (int i = 0; i < n * m; i++){
        if (a[i].id == 0) pos = i + 1;
    }
    int c = ceil(1.0 * pos / n);
    int r = pos - (pos - 1) / n * n;
    if (c % 2 == 0) r = n - r + 1;
    cout << c << ' ' << r;
    return 0;
}
