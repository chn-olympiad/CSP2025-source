#include <iostream>
#include <cstring>

#define ull unsigned long long

using namespace std;

const int maxn = 1e6 + 10;
const ull base = 131;

ull s1[maxn], s2[maxn], pw[maxn];
char a[maxn], b[maxn], s[maxn], t[maxn];
int n, q;
struct chg {
	int l;
	ull n1, n2;
} rl[maxn];

ull cal1(int l, int r) {
	return s1[r] - s1[l - 1] * pw[r - l + 1];
}
ull cal2(int l, int r) {
	return s2[r] - s2[l - 1] * pw[r - l + 1];
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i < maxn; i++) pw[i] = pw[i - 1] * base;
	for (int i = 1; i <= n; i++) {
		cin >> (a + 1) >> (b + 1);
		rl[i].l = strlen(a + 1);
		for (int j = 1; j <= rl[i].l; j++)
			rl[i].n1 = rl[i].n1 * base + a[j];
		for (int j = 1; j <= rl[i].l; j++)
			rl[i].n2 = rl[i].n2 * base + b[j];
	}
	while (q--) {
		int ans = 0;
		cin >> (s + 1) >> (t + 1);
		int ls = strlen(s + 1), lt = strlen(t + 1);
		// cout << ls << " " << lt << "qwq\n";
		if (ls != lt) { cout << "0\n"; continue; } 
		for (int i = 1; i <= ls; i++) s1[i] = s1[i - 1] * base + s[i];
		for (int i = 1; i <= lt; i++) s2[i] = s2[i - 1] * base + t[i];
		for (int i = 1; i <= n; i++) {
			int l = 1, r = ls, L = 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (cal1(1, mid) == cal2(1, mid)) L = mid, l = mid + 1;
				else r = mid - 1;
			}
			int R = ls;
			l = 1, r = ls;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (cal1(mid, ls) == cal2(mid, ls)) r = mid - 1, R = mid;
				else l = mid + 1;
			}
			// cout << L << " " << R << "\n";
			L++, R--;
			if (R - L + 1 > rl[i].l) continue; 
			for (int j = 1; j + rl[i].l - 1 <= ls; j++) {
				if (cal1(j, j + rl[i].l - 1) == rl[i].n1 && cal2(j, j + rl[i].l - 1) == rl[i].n2)
					if (cal1(1, j - 1) == cal2(1, j - 1) && cal1(j + rl[i].l, ls) == cal2(j + rl[i].l, lt))
							ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}