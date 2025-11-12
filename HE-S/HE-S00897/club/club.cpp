#include <bits/stdc++.h>

#define ll long long

const ll N = 1e5 + 5;

ll n, a[N][5];
typedef std::pair<ll, ll> pai;
std::priority_queue<pai, std::vector<pai>, std::greater<pai> > q[5];
ll ans;

ll read() {
	ll res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(ll x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

inline void push(ll i, ll p) {
	if (p == 1) {
		ans += a[i][1];
		q[1].push(std::make_pair(a[i][1] - std::max(a[i][2], a[i][3]), i));
	} else if (p == 2) {
		ans += a[i][2];
		q[2].push(std::make_pair(a[i][2] - std::max(a[i][1], a[i][3]), i));
	} else {
		ans += a[i][3];
		q[3].push(std::make_pair(a[i][3] - std::max(a[i][1], a[i][2]), i));
	}
}

void Main() {
	n = read();
	for (ll i = 1; i <= n; ++i)
		a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
	while (q[1].size()) q[1].pop();
	while (q[2].size()) q[2].pop();
	while (q[3].size()) q[3].pop();
	ans = 0;
	for (ll i = 1, p; i <= n; ++i) {
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			push(i, 1);
			if (q[1].size() > (n >> 1)) {
				p = q[1].top().second;
				q[1].pop();
				ans -= a[p][1];
				if (a[p][2] >= a[p][3]) push(p, 2);
				else push(p, 3);
			}
		} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			push(i, 2);
			if (q[2].size() > (n >> 1)) {
				p = q[2].top().second;
				q[2].pop();
				ans -= a[p][2];
				if (a[p][1] >= a[p][3]) push(p, 1);
				else push(p, 3);
			}
		} else {
			push(i, 3);
			if (q[3].size() > (n >> 1)) {
				p = q[3].top().second;
				q[3].pop();
				ans -= a[p][3];
				if (a[p][1] >= a[p][2]) push(p, 1);
				else push(p, 2);
			}
		}
	}
//	std::cerr << q[1].size() << ' ' << q[2].size() << ' ' << q[3].size() << std::endl;
	write(ans), puts("");
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll T = read();
	while (T--) Main();
	return 0;
}

/*
15:10
40min
100pts
I'm so vegetable.
*/
