#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, id;
    bool operator < (const node& y) const {
        return x > y.x;
    }
} a[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1;i <= n * m;i++) 
        cin >> a[i].x, a[i].id = i;
    sort(a+1, a+n*m+1); 
    int pos = 1;
    while(a[pos].id != 1) pos++;
    int c = pos / n + (pos % n != 0);
    int r = (pos % n != 0 ? pos % n : n);
    if(c % 2 == 0) r = n - r + 1;
    cout << c << " " << r << endl;
    return 0;
}