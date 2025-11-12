#include<bits/stdc++.h>
using namespace std;

int const N = 15;
int f[N][N], a[N * N];
int n, m;
int R;

int r = 1, c = 1;

void find(){
    for(int k = 1; k <= n * m; k++){
        f[r][c] = a[k];
        if(f[r][c] == R) {cout << c << " " << r << "\n"; break;}
        if(c & 1){
            if(r + 1 > n) c ++;
            else r ++;
        }else{
            if(r - 1 < 1) c ++;
            else r --;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];

    R = a[1];
    sort(a + 1, a + n * m + 1, [](int x, int y){return x > y;});

    find();

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << f[i][j] << " ";
        }cout << "\n";
    }
    */

    return 0;
}


// Kasty's code