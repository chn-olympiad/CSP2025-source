#include <iostream>
#include <ios>
#include <algorithm>
#include <map>

using namespace std;

int t, n, ans;
int a[5][100005];
int l[20005];

namespace N_less_than_4 {

int dfs(int step, int p1, int p2, int p3, int cnt) {
	if (step == n + 1) {
		if (p1 <= n / 2 && p2 <= n / 2 && p3 <= n / 2)
			return ans = max(ans, cnt);
		return 0;
	}
	
	if (p1 < n / 2) dfs(step + 1, p1 + 1, p2, p3, cnt + a[1][step]);
	if (p2 < n / 2) dfs(step + 1, p1, p2 + 1, p3, cnt + a[2][step]);
	if (p3 < n / 2) dfs(step + 1, p1, p2, p3 + 1, cnt + a[3][step]);
	return 0;
}
}

namespace special_A {
	bool cmp(int x, int y) {
		return x > y;
	} 
	
	void solve() {
		sort(a[1] + 1, a[1] + n + 1, cmp);
		long long ans = 0;
		for (int i = 1; i <= n / 2; i++) {
//			cout << a[1][i] << endl; 
			ans += a[1][i];
		}
		
		cout << ans << endl;
	}
}

namespace special_B {
	bool cmp(int x, int y) {
		return x > y;
	}
	
	bool cmp2(int x, int y) {
		return a[1][x] > a[1][y];
	}
	
	void solve() {
		for (int i = 1; i <= n; i++) {
			l[i] = i;
		}
		

		
		sort(l + 1, l + n + 1, cmp2);
//		for (int i = 1; i <= n; i++) {
//			cout << l[i] << ' ';
//		}
		
//		
		
		long long ans = 0, cnt = 0;
		
		for (int i = 1; i <= n / 2; i++) {
			if (a[1][l[i]] < a[2][l[i]]) {
				ans += a[2][l[i]];
				a[1][l[i]] = 0;
				a[2][l[i]] = 0;
				cnt++;
			} else {
				ans += a[1][l[i]];
				a[1][l[i]] = 0;
				a[2][l[i]] = 0;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			if (a[1][i] > a[2][i] && cnt > 0) {
				ans += a[1][i];
				cnt--;
				a[1][i] = 0;
				a[2][i] = 0;
			} else {
				ans += a[2][i];
				a[1][i] = 0;
				a[2][i] = 0;
			}
		}
		
//		for (int i = 1; i <= n; i++) {
//			cout << a[1][i] << ' ' << a[2][i] << endl;
//		}
//		
		cout << ans << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while (t--) {
		ans = 0;
		bool sa = true, sb = true;
		
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if (a[2][i] != 0 || a[3][i] != 0) {
				sa = false;
			}
			if (a[3][i] != 0) {
				sb = false;
			}
		}
		
		int k = n / 2;
		if (n <= 10) {
			N_less_than_4::dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
		} else if (sa) {
			special_A::solve();
		} else if (sb) {
			special_B::solve();
		} else {
			cout << "I can't solve this sub-problem. woyao pianfen!!!" << endl;
		}
	}
	
	return 0;
}
 
