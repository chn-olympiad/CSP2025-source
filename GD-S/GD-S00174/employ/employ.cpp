#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 510;
constexpr ll mod = 998244353;

using namespace std;

int n, m;
int c[N];
bitset<N> st;
ll ans = 0;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> st;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    if (st.count() == n) {
    	ans = 1;
    	for (int i = 1; i <= n; ++i) {
        	ans = (ans * i) % mod;
    	}
	} 
	else {
		sort(c + 1, c + 1 + n);
		do {
			int t = 0;
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				cout << c[i] << ' ';
				if (c[i] < cnt || st[n - i] == 0) {
					cnt += 1;
					continue;
				}
				t += 1;
			}
			if (t >= m) ans = (ans + 1) % mod;
		} while (next_permutation(c + 1, c + 1 + n));
		ans -= 1;
	}
    
    cout << ans << '\n';
    return 0;


}
