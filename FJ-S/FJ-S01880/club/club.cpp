#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int T, n;

struct Stu {
	int x, y, z;
	int diff;
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		
		vector<Stu> a, b, c;
		long long ans = 0;
		
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			if (x == max(x, max(y, z))) a.push_back({x, y, z, x - max(y, z)});
			else if (y == max(x, max(y, z))) b.push_back({x, y, z, y - max(x, z)});
			else c.push_back({x, y, z, z - max(x, y)});
			ans += max(x, max(y, z));
		}
		
		
		if (a.size() > n / 2) {
			sort(a.begin(), a.end(), [](const Stu& a, const Stu& b){
				return a.diff < b.diff;
			});
			for (int i = 0; i < a.size() - n / 2; i++) {
				ans -= a[i].diff;
			}
		}
				
		else if (b.size() > n / 2) {
			sort(b.begin(), b.end(), [](const Stu& a, const Stu& b){
				return a.diff < b.diff;
			});
			for (int i = 0; i < b.size() - n / 2; i++) {
				ans -= b[i].diff;
			}
		}
		
		else if (c.size() > n / 2){
			sort(c.begin(), c.end(), [](const Stu& a, const Stu& b){
				return a.diff < b.diff;
			});
			for (int i = 0; i < c.size() - n / 2; i++) {
				ans -= c[i].diff;
			}
		}
		
		cout << ans << endl;
	}
}
