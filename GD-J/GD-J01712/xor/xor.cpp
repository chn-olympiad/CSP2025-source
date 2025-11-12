#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
	int l, r;
};

ll n, k;
ll a[100005], s[100005];
vector <edge> m;

bool cmp(edge x, edge y) {
	return x.r < y.r;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			if((s[j] ^ s[i - 1]) == k) {
				m.push_back({i, j});
			}
		}
	}
	sort(m.begin(), m.end(), cmp);
	int ans = 0, ur = -1;
	for(int i = 0; i < m.size(); i ++) {
		if(m[i].l > ur) {
			ans += 1;
			ur = m[i].r;
		}
	}
	cout << ans;
}
// 가가가가가가가가가가가가가가가가가가가 
