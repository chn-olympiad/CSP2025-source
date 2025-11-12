#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int a[maxn];

bool cmp(int idxa, int idxb) {
	return a[idxa] < a[idxb];
} 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> c1, c2, c3;
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			int mx = max(max(a1, a2), a3);
			a1 = mx - a1;
			a2 = mx - a2;
			a3 = mx - a3;
			if(a1 <= a2 && a1 <= a3) {
				a[i] = min(a2, a3);
				c1.push_back(i);
			}
			else if(a2 <= a1 && a2 <= a3) {
				a[i] = min(a1, a3);
				c2.push_back(i);
			}
			else {
				a[i] = min (a1, a2);
				c3.push_back(i);
			}
			ans += mx;
		}
		if(c1.size() > (n/2)) {
			int k = c1.size();
			sort(c1.begin(), c1.end(), cmp);
			int i = 0;
			while(k > (n/2)) {
				k--;
				ans -= a[c1[i++]];
			}
		}
		else if(c2.size() > (n/2)) {
			int k = c2.size();
			sort(c2.begin(), c2.end(), cmp);
			int i = 0;
			while(k > (n/2)) {
				k--;
				ans -= a[c2[i++]];
			}
		}
		else if(c3.size() > (n/2)) {
			int k = c3.size();
			sort(c3.begin(), c3.end(), cmp);
			int i = 0;
			while(k > (n/2)) {
				k--;
				ans -= a[c3[i++]];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
