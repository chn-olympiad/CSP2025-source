#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i) 
using namespace std;

const int N = 5 * 1e5 + 5;
int n, k, a[N], ans;

int query(int l, int r) {
	int res = a[l];
	inc(i, l + 1, r) {
		res = res xor a[i];
	}
	return res;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;

	inc(i, 1, n) cin >> a[i];
	
	inc(len, 1, n) {
		//cout << "len=" << len << " ";
		int res = a[1], f = 0;

		inc(i, 2, n) {
			if(i % len == 1) {
				//cout << res << " ";
				if(res != k) {
					f = 1;
					break;
				}
				res = a[i];
			} else {
				res ^= a[i];
			}
		}
		if(f == 0) {
			ans = max(ans, len);
		}
	}
	cout << ans << '\n';
	
	return 0; 
}
