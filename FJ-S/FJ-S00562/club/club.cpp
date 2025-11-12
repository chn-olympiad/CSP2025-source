#include <bits/stdc++.h>
#define ri register int

using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0; bool f = 1;
	char ch = getchar();
	while(ch < 48 || ch > 57) {
		if(ch == 45) f = 0;
		ch = getchar();
	}
	while(ch >= 48 && ch <= 57) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return f ? x : -x;
}

constexpr int N = 1e5 + 3;

int n;
int a[N][3];

vector<int> v[3];
priority_queue<int> q;

inline void Solve() {
	ll ans = 0;
	n = rd();
	for(ri i = 1; i <= n; ++i) {
		int pos = 0;
		for(ri j = 0; j < 3; ++j) {
			a[i][j] = rd();
			if(a[i][pos] < a[i][j]) pos = j;
		}
		v[pos].emplace_back(i);
		ans += a[i][pos];
	}
	
	for(ri pos = 0; pos < 3; ++pos) 
	if(v[pos].size() > n / 2) {
		int siz = v[pos].size();
		for(auto i : v[pos]) {
			int ma = 0;
			for(ri j = 0; j < 3; ++j) {
				if(j == pos) continue;
				ma = max(ma, a[i][j]);
			}
			q.push(ma - a[i][pos]);
		}
		while(siz > n / 2) {
			ans += q.top();
			q.pop();
			--siz;
		}
		break;
	}
	
	printf("%lld\n", ans);
	for(ri pos = 0; pos < 3; ++pos) v[pos].clear();
	while(q.size()) q.pop();
	
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	for(ri T = rd(); T--; ) 
	Solve();
	return 0;
}

