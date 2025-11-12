#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, s, x, rk = 1, px, py;
    cin >> n >> m >> s;
    for(int i = 1; i < n * m; i++){
        cin >> x;
        if(x > s)rk++;
    }
    px = (rk - 1) / n + 1;
    if(px & 1)py = (rk - 1) % n + 1;
    else py = n - (rk - 1) % n;
    cout << px << " " << py;
    return 0;
}
