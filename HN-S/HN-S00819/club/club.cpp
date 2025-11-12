#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int T;
int n;
struct Value {
	int id;
	int val;
};
Value a[N];
Value b[N];
Value c[N];

bool has[N];
int as = 0, bs = 0, cs = 0;
int ans = 0;
int m = 0;

bool cmp(Value a, Value b) {
	return a.val > b.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while(T--) {
		for(int i = 0; i < N; i++) {
			a[i].val = 0;
			b[i].val = 0;
			c[i].val = 0;
		}
		ans = 0;
		as = 0;
		bs = 0;
		cs = 0;
		memset(has, false, sizeof(has));
		cin >> n;
		m = n / 2;
		for(int i = 0; i < n; i++) {
			cin >> a[i].val >> b[i].val >> c[i].val;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
		}
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		sort(c, c + n, cmp);
		
		for(int i = 0; i < n / 2; i++) {
			ans += a[i].val;
		}
		cout << ans << '\n';
	}
	return 0;
} 
