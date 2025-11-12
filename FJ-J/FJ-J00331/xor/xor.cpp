#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
#define pp pop_back
//#define _x first
//#define _y second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 5e5 + 7, INF = 0x3f3f3f3f;

void put(ll x, char el = '\n') {
	prt("%lld", x);
	putchar(el);
}

int a[N], s[N];

struct seg {
	int l, r;
	bool operator < (const seg &b) const {
		if (r - l + 1 != b.r - b.l + 1) return (r-l+1) < (b.r-b.l+1);
		else {
			if (l != b.l) return l < b.l;
			else return r < b.r;
		}
	}
};

//struct BIT {
//	int tr[N];
//	void lb(int x) {
//		return x & -x;
//	}
//	void add(int x, int k) {
//		for (int i = x; i <= n; i += lb(i)) tr[i] += y;
//	}
//	void query(int x) {
//		int ans = 0;
//		for (int i = x; i >= 1; i -= lb(i)) ans += tr[i];
//		return ans;
//	}
//} f;

int query(int l, int r) {
	return s[r] ^ s[l-1];
}
bool f[N];
vector<seg> v;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		s[i] = s[i-1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (query(i, j) == k) v.pb({i ,j});
		}
	}
	int ans = 0;
	sort(v.begin(), v.end());
	for (auto i : v) {
		int l = i.l, r = i.r, flag = 0;
		for (int i = l; i <= r; i++) flag = max(flag, (int)f[i]);
//		printf("l = %d r = %d flag = %d\n", l, r, flag);
		if (flag) continue;
		for (int i = l; i <= r; i++) f[i] = 1;
		ans++;
	}
	put(ans);
//	fclose(stdin); fclose (stdout);
	return 0;
}

