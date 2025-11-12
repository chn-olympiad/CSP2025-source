#include <bits/stdc++.h>
#define rep(a,b,c) for (int (a)=(b); (a)<=(c); ++(a))
#define per(a,b,c) for (int (a)=(b); (a)>=(c); --(a))
using namespace std;
const int N=1e5+5;

int n, lim, a[5][N], f[N/2][N/2][N/2], ans;

void source(){
    cin >> n;
    lim = n/2;
    rep(i, 1, n)
        cin >> a[1][i] >> a[2][i] >> a[3][i];

    rep(i, 1, n)
        per(x, lim, 1)
            per(y, lim, 1)
            	per(z, lim, 1){
		            f[x][y][z] = max({ f[x][y][z],
		                             f[x-1][y][z]+a[1][i],
		                             f[x][y-1][z]+a[2][i],
		                             f[x][y][z-1]+a[3][i]} );
            	ans = max(ans, f[x][y][z]);
        }
    cout << ans << '\n';
    return ;
}

void clr(){
    rep(i, 1, lim)
        rep(j, 1, lim)
            rep(k, 1, lim)
            	f[i][j][k] = 0;
    return ;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        source(), clr();
    }
    return 0;
}
