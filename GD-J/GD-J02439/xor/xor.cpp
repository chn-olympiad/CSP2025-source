#include <iostream>
#include <vector>

using namespace std;

struct qj {
	int l, r;
};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> ns(n);
	for (int &i : ns) {
		cin >> i;
	}
	if (k == 0) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (ns[i] == 0) {
				ans++;
			}
			if (i == n - 1) {
				break;
			}
			if (ns[i] == ns[i + 1]) {
				ans++;
			}
		}
		cout << ans << endl;
	} else {
		vector<qj> qjs;
		for (int i = 0; i < n; i++) {
			int cu = 0;
			for (int j = i; j < n; j++) {
				cu ^= ns[j];
				if (cu == k) {
					qjs.push_back({i, j});
					break;
				}
			}
		}
		vector<qj> newqjs;
		int cu = -1;
		for (int i = 0; i < qjs.size(); i++) {
			if (qjs[i].l > cu) {
				cu = qjs[i].r;
				newqjs.push_back(qjs[i]);
			} else {
				if (qjs[i].r < newqjs[newqjs.size() - 1].r) {
					newqjs[newqjs.size() - 1] = qjs[i];
					cu = qjs[i].r;
				}
			}
		}
		cout << newqjs.size() << endl;
	}
	return 0;
}
