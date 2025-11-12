#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
int n, m, A[N], cnt, ans, res;

signed main() {
//	freopen("seat3.in", "r", stdin);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) {
		cin >> A[i];
		if(A[i] >= A[1]) cnt ++;
	}
	
	ans = cnt / n;
	res = cnt - ans * n;
//	cerr<<ans<<"::"<<res<<"\n";
	if(0 == res) res = n;
	else ans ++;
	
	if(0 == (ans & 1)) res = n - res + 1;
	
	cout << ans << " " << res;
	return 0;
}
