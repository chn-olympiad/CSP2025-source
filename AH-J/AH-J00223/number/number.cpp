#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define DLN(x) cout << #x << "\t = " << x << '\n';
#define CDLN(x, l, r) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << x[_IDX] << ' '; cout << "]\n";
#define CCDLN(x, l, r, what) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << what << ' '; cout << "]\n";

using ll = long long;
template <typename T>
using vec = vector<T>;


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vec<int> ns;

	for (char c : s) {
		if (c >= '0' && c <= '9') {
			ns.push_back(c - '0');
		}
	}

	sort(ns.begin(), ns.end(), [](int a, int b) {
		return a > b;
	});

	for (int v : ns) {
		printf("%d", v);
	}
	puts("");

	return 0;
}
