#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 10 + 10, INF = 9e18;
int n,m,cheng;
int a[N*N];
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n * m) cin >> a[i];
    cheng = a[1];
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    int x(1), y(1), dir(1), cnt(1);
    while(x <= n && y <= m){
        if(a[cnt] == cheng){
            cout << y << ' ' << x;
            return 0;
        }
        x += dir; cnt++;
        if(x == n + 1){
            dir = -1, x = n, y++;
        }
        else if(x == 0){
            dir = 1, x = 1, y++;
        }
    }


    return 0;
}
