#include<bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;
const int N = 5e3 + 6;
int n, a[N], f = 1, ans;
int spe(){
    return (1 << n) - n * n / 2 - n / 2 - 1;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    fr(i, 1, n) cin >> a[i], f &= a[i] == 1;
    if (f){ cout << spe(); return 0; }
    fr(i, 1, 1 << n){
        int tot = 0, maxx = 0, tmp = i, cnt = 0;
        fr(j, 1, n){
            if (tmp & 1) tot += a[j], cnt ++, maxx = max(maxx, a[j]);
            tmp >>= 1;
        }
        if (cnt >= 3 && maxx * 2 < tot) ans ++;
    }
    cout << ans;
	return 0;
}