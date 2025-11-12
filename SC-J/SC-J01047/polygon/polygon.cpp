#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll maxn = 5005, mod = 998244353;

ll n, arr[maxn];
void Input() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld", &arr[i]);
	}
}

bool cmp(ll a, ll b) {
	return a > b;
}

ll ans;
void DFS(ll p, ll sum, ll up) {
	if (p > n) {
		if (sum > up) {
			++ans;
		}
		if (ans == mod) {
			ans = 0;
		}
		return;
	}
	DFS(p + 1, sum, up);
	DFS(p + 1, sum + arr[p], up);
}

void Solve() {
	sort(arr + 1, arr + n + 1, cmp);
	for (ll i = 1; i <= n - 2; ++i) {
		DFS(i + 1, 0, arr[i]);
	}
}

void Print() {
	printf("%lld", ans);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	Input();
	Solve();
	Print();
	return 0;
}