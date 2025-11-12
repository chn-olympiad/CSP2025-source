// Stage III - 阿波罗经络
#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
using ll = long long;
int in(void) { int x; scanf("%d", &x); return x; }
const int kN = 105000;
int v[kN][3], c[kN];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = in();
	while(T--) {
		int n = in();
		int cnt[3] = {};
		ll ans = 0;
		_rep(i,1,n) {
			_rep(j,0,2) v[i][j] = in();
			c[i] = max_element(v[i], v[i] + 3) - v[i];
			++cnt[c[i]]; ans += v[i][c[i]];
		}
		_rep(i,0,2) if(cnt[i] > n / 2) {
			priority_queue<int> q;
			_rep(j,1,n) if(c[j] == i) 
				q.push(max(v[j][(i + 1) % 3], v[j][(i + 2) % 3]) - v[j][i]);	
			_rep(j,1,cnt[i] - n / 2) ans += q.top(), q.pop();
		}
		printf("%lld\n", ans);
	} 
	return 0;
}