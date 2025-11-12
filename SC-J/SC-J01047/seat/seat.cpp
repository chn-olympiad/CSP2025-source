#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll maxn = 15, maxm = 15;

ll n, m, arr[maxn * maxm];
void Input() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= (n * m); ++i) {
		scanf("%lld", &arr[i]);
	}
}

bool cmp(ll a, ll b) {
	return a > b;
}

ll cnt, Rc, ansa, ansb;
bool w;
void Solve() {
	Rc = arr[1];
	sort(arr + 1, arr + (n * m) + 1, cmp);
	for (ll i = 1; i <= (n * m); ++i) {
		if (arr[i] == Rc) {
			cnt = i;
		}
	}

	for (ll i = 1; i <= m; ++i) {
		ll st = (i - 1) * n + 1, en = i * n;
		if (cnt >= st && cnt <= en) {
			ansa = i;
			break;
		}
	}

	if (ansa % 2 == 1) {
		w = true;
	}

	if (w == true) {
		ansb = cnt - ((ansa - 1) * n);
	} else {
		ansb = n - (cnt - (ansa - 1) * n) + 1;
	}
}

void Print() {
	printf("%lld %lld", ansa, ansb);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	Input();
	Solve();
	Print();
	return 0;
}