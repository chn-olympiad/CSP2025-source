#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
constexpr ll N = 5 + 1e5;

ll t, n, a[N][5], c[N][5], ans;
vector<pll> b[5]; // <will decr, i>
void go() {
	// reset
	ans = 0;
	up (i, 1, 3) b[i].clear();
	cin >> n;
	up (i, 1, n) {
		// reset
		ll *ai = a[i], &c1 = c[i][1], &c2 = c[i][2], &c3 = c[i][3];
		ai[0] = -1, c1 = c2 = c3 = 0;
		up (j, 1, 3) {
			cin >> ai[j];
			// into right place
			if (ai[j] > ai[c1]) 		c3 = c2, c2 = c1, c1 = j;
			else if (ai[j] > ai[c2]) 	c3 = c2, c2 = j;
			else 						c3 = j;
		}
		b[c1].emplace_back(ai[c1] - ai[c2], i);
		ans += ai[c1];
	}
	ll id = -1, cnt = -1; // cnt: how much greater
	up (i, 1, 3) if(b[i].size() > n / 2) // too big
		id = i, cnt = b[i].size() - n / 2;
	if (id != -1) {
		auto& v = b[id];
		sort(v.begin(), v.end()); // minimal decr
		up (i, 0, cnt - 1) {
			ans -= v[i].first; // decr it
			ll u = v[i].second;
			b[c[u][2]].emplace_back(0, u);
		}
		vector<pll>(v.begin() + cnt, v.end()).swap(v); // last n/2 per
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) go();
	return 0;
}
