#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N*N], n, m, c, r, rk, fen, f[N][N];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n*m; i++) cin >> a[i];
    fen = a[1];
    sort(a+1, a+n*m+1);
    for(int i=1; i<=n*m; i++){
        if(a[i]==fen) rk=n*m-i+1;
    }
    if(rk%n==0) c=rk/n;
    else c=rk/n+1;
    if(c%2==1){
        if(rk%n==0) r=n;
        else r=rk%n;
    }
    else r=(n-rk%n)%n+1;
    cout << c << ' ' << r;
    return 0;
}
