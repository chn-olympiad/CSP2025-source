//2025CSP-J/S rp++
//please be a nice score!
#include <bits/stdc++.h>
using namespace std;

int a[111];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[j * n - n + i];
        }
    }
    int rscore = a[1], rrank = -1;
    sort(a + 1, a + n * m + 1);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == rscore){
            rrank = i;
        }
    }
    rrank = n * m - rrank + 1;
    //cout << rrank << "\n";
    int col = (rrank - 1) / n + 1;
    if(col % 2 == 1){
        cout << col << " " << (rrank - 1) % n + 1;
    }
    else{
        cout << col << " " << n - ((rrank - 1) % n + 1) + 1;
    }
    return 0;
}
