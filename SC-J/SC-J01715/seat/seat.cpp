#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)



const int mod = 7 + 1e9;
const int N = 3 + 2e5;

mt19937 rnd(time(NULL));


int n, m;
PII a[N];

int main() {
//	freopen("D:\\work\\number\\number4.in", "r", stdin);
//	freopen("D:\\work\\number\\number4.out", "w", stdout);	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n * m + 1, greater<PII>());

	int x = 1, y = 1;
	int flag = 1;
	for (int i = 1; i <= n * m; ++i) {
		if (a[i].second == 1) {
			cout << y << " " << x;
			return 0;
		}
		if (1 <= x + flag && x + flag <= n) {
			x += flag;
		} else {
			y += 1;
			flag = -flag;
		}
	}
	
	return 0;
} 