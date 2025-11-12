#include <bits/stdc++.h>

#define fir first
#define sec second

#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)

#define mkp make_pair
#define epb emplace_back
#define pb pop_back
#define sz(a) (int)(a.size())
#define All(a) begin(a), end(a)
#define mem(a, x) memset(a, x, sizeof(a))

using namespace std;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T>
void chkmax(T &x, T y) {
	if (x < y) x = y;
}
template<typename T>
void chkmin(T &x, T y) {
	if (x > y) x = y;
}

const int kN = 1e5 + 10;

int T;

int n;

int val[kN][3], mx_pos[kN];

int cnt[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while (T--) {
		mem(cnt, 0);
		cin >> n;
		ll ans = 0;
		L(i, 1, n) {
			mx_pos[i] = 0;
			L(j, 0, 2) {
				cin >> val[i][j];
				if (val[i][j] > val[i][mx_pos[i]]) {
					mx_pos[i] = j;
				}
			}
			ans += val[i][mx_pos[i]];
			++cnt[mx_pos[i]];
		}
		int pos = -1;
		L(i, 0, 2) {
			if (cnt[i] > n / 2) pos = i;
		}
		if (pos == -1) {
			cout << ans << '\n';
			//cout << "!\n";
		} else {
			vi vec;
			L(i, 1, n) {
				if (mx_pos[i] == pos) {
					int mx = 0;
					L(j, 0, 2) {
						if (j != pos) {
							chkmax(mx, val[i][j]);
						}
					}
					vec.epb(mx - val[i][mx_pos[i]]);
				}
			}
			sort(All(vec), greater<>());
			L(i, 0, cnt[pos] - n / 2 - 1) ans += vec[i];
			cout << ans << '\n';
		}
	}
	return 0;
}
