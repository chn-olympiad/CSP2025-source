#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[105], t, pos, cnt;
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    t = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= m; i++){
        if (i % 2){
            for (int j = 1; j <= n; j++){
                cnt++;
                if (a[cnt] == t){
                    cout << i << " " << j;
                    return 0;
                }
            }
        } else {
            for (int j = n; j >= 1; j--){
                cnt++;
                if (a[cnt] == t){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
/*

//freopen("seat.in", "r", stdin);
//freopen("seat.out", "w", stdout);

*/
