#include<bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;
int n, m, a[104], r;
bool cmp(int x, int y){ return x > y; }
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fr(i, 1, n * m) cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	fr(i, 1, n * m) if (a[i] == r){
		int x = (i - 1) / n + 1, y = (i - 1) % m + 1;
		if (x % 2 == 0) y = m + 1 - y;
		cout << x << " " << y; return 0;
	}
	return 0;
}