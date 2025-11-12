#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 25; 

int n, k, a[N];
int f[N], g[N], q[N];
map<int, int> mp;
// f[i] 表示前 i 个数中最多可以构成多少个区间，并且选了 f[i]
// g[i] 表示 f[1], f[2] ... f[i] 的最大值 

//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
		
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		q[i] = q[i - 1] ^ a[i];
		
		int x = mp[q[i] ^ k];
		
		if ((q[i] ^ k) == 0) f[i] = g[x] + 1;
		else if (x != 0 && (q[x] ^ q[i]) == k) f[i] = g[x] + 1;
		g[i] = max(f[i], g[i - 1]);
		
		mp[q[i]] = i;
		
//		int x = 0;
//		for (int j = i; j >= 1; j--) {
//			x ^= a[j];
//			
//			if (x == k) {
//				f[i] = g[x] + 1;
//				break;
//			}
//		}
//		g[i] = max(f[i], g[i - 1]);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	
	cout << ans << endl;
	return 0;
}
