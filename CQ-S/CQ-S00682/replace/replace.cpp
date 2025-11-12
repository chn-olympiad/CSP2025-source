#include <bits/stdc++.h>
#define L(name, start, end) for (int name = start; name <= end; ++name)
#define R(name, start, end) for (int name = start; name >= end; --name)
using namespace std;

constexpr int N = 200005;
namespace mains{
	pair<string, string> a[N];
	pair<string, vector<string>> f[N];
	int n, m;
	int tot = 0;
	bool compare(string x, string y, int start, int end) {
		for (int i = start; i <= end; ++i) {
			if (x[i] != y[i]) {
//				cout << "compare [" << x << "] and [" << y << "] but different on " << i << "!\n";
				return 0;
			}
		}
		return 1;
	}
	int find(string x, string y) {
		int size = x.size(), size2 = y.size();
		L(i, 0, size) {
			bool flag = 1;
			if(i + size2 - 1 > size) break;
			L(j, 0, size2 - 1) {
				if(x[i + j] != y[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
//				cout << "[ok!] ";L(j, 0, size2 - 1)cout << x[i + j];cout << '\n';
				return i;
			}
		}
		return -1;
	}
	bool check(string x, string y, string need, int start, int end) {
		int size = x.size();
		L(i, 0, start - 1) if(x[i] != y[i]) return 0;
		L(i, end + 1, size - 1) if (x[i] != y[i]) return 0;
		int tot = 0;
		L(i, start, end) {
			if (y[i] != need[tot]) return 0;
			tot++;
		}
		return 1;
	}
	int run(int test) {
		cin >> n >> m;
		tot = 0;
		L(i, 1, n) cin >> a[i].first >> a[i].second, f[i].second.clear();
		sort(a + 1, a + 1 + n);
		L(i, 1, n) {
			if (a[i].first != a[i - 1].first) {
				tot++;
				f[tot].first = a[i].first, f[tot].second.push_back(a[i].second);
			} else {
				f[tot].second.push_back(a[i].second);
			}
		}
		
		L(i, 1, m) {
			string x, y;
			cin >> x >> y;
			int size = x.size();
			x = " " + x, y = " " + y;
			int l = 0, r = size, ans = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (compare(x, y, 1, mid)) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			int ll = ans + 1, rr = n;
			R(i, size, ans + 1) {
				if (x[i] != y[i]) {
					rr = i;
					break;
				}
			}
			int len = 0; string need = "", need2 = "";
			L(i, ll, rr)need += x[i], len++;
			L(i, ll, rr)need2 += y[i];
			int cnt = 0;
			L(i, 1, tot) {
				int start = find(f[i].first, need);
				if (start == -1) continue;
//				cout << "[check on]" << f[i].first << '\n';
				int end = start + len - 1;
				for (auto x : f[i].second) {
					if (check(f[i].first, x, need2, start, end)) {
						++cnt;
//						cout << f[i].first << ' ' << x << '\n';
					}
				}
			}
			cout << cnt << '\n';
//			cout << "[difference] ";L(i, ll, rr)cout << x[i]; cout << ' '; L(i, ll, rr)cout << y[i];cout << '\n';
		}
		return 0;
	}
}using namespace mains;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 1;
//	cin >> T;
	L(i, 1, T){
		run(i);
	}

	return 0;
}

