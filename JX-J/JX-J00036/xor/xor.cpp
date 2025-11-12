#include<bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;
const int N = 5e5 + 6;
int n, k, a[N], f = 1, ans, l;
int spe(){
    int num[3] = {-1, 0, 0}, cnt = 0;
    fr(i, 1, n + 1){
        if (a[i]) num[1] ++, cnt ++;
        else num[2] += cnt >> 1, cnt = 0, num[0] ++;
    }
    return k ? num[1] : num[0] + num[2];
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i], f &= a[i] <= 1;
    if (f){ cout << spe(); return 0; }
    fr(i, 1, n) for (int tot = 0, j = i; j > l; j --){
        tot ^= a[j];
        if (tot == k){ ans ++, l = i; break; }
    }
    cout << ans;
	return 0;
}