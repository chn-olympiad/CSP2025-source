/**
 * @brief CSP-S 2025
 *        Problem A. club
 * @author BJ-S00244    liuli688
*/
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1e5 + 10;
int T, n, ans;

class Member {
public:
	int a1, a2, a3, m1, m2, m3;
} a[N];

int main(int argc, const char *argv[]) {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (cin >> T; T--; ) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].m1 = 1; a[i].m2 = 2; a[i].m3 = 3;
			if (a[i].a1 < a[i].a2)
				std::swap(a[i].a1, a[i].a2), std::swap(a[i].m1, a[i].m2);
			if (a[i].a1 < a[i].a3)
				std::swap(a[i].a1, a[i].a3), std::swap(a[i].m1, a[i].m3);
			if (a[i].a2 < a[i].a3)
				std::swap(a[i].a2, a[i].a3), std::swap(a[i].m2, a[i].m3);
		}
		std::sort(a + 1, a + n + 1, [](const Member& lhs, const Member& rhs) {
			return (lhs.a1 - lhs.a2 == rhs.a1 - rhs.a2) ? (lhs.a1 + rhs.a2 > rhs.a1 + lhs.a2) : (lhs.a1 - lhs.a2 > rhs.a1 - rhs.a2);
		});
		ans = 0;
		int c[4] = {0, 0, 0, 0}, i = 1;
		for (; i <= n; ++i) {
            if (c[a[i].m1] == n / 2)
                break;
            ans += a[i].a1;
            ++c[a[i].m1];
		}
		std::sort(a + i, a + n + 1, [](const Member& lhs, const Member& rhs) {
			return (lhs.a2 - lhs.a3 == rhs.a2 - rhs.a3) ? (lhs.a2 + rhs.a3 > rhs.a2 + lhs.a3) : (lhs.a2 - lhs.a3 > rhs.a2 - rhs.a3);
		});
		for (; i <= n; ++i)
			if (c[a[i].m1] < n / 2)
                ans += a[i].a1, ++c[1];
            else if (c[a[i].m2] < n / 2)
                ans += a[i].a2, ++c[2];
            else if (c[a[i].m3] < n / 2)
                ans += a[i].a3, ++c[3];
            else
                throw;
		cout << ans << '\n';
	}
	return 0;
}

///passwd: Ren5Jie4Di4Ling5%
