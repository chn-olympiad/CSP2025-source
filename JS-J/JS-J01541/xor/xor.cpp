// From ZZY 2025.11.1 乱写一通
#include <algorithm>
#include <fstream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

int pos[1 << 21];

int main()
{
	fill_n(pos, 1 << 21, -1);
	ifstream in("xor.in");
	ofstream out("xor.out");
	int n, k;
	in >> n >> k;
	vector<int> v(n);
	for (auto& e : v) in >> e;
	partial_sum(v.begin(), v.end(), v.begin(), [](int a, int b) { return a ^ b; });
	vector<pair<int, int>> sgt;
	for (int i = 0; i < n; i++) {
		if ((v[i] ^ k) == 0 || pos[v[i] ^ k] != -1) sgt.push_back({pos[v[i] ^ k] + 1, i});
		pos[v[i]] = i;
	}

	int lst = -1, ans = 0;
	for (const auto& e : sgt) {
		if (e.first > lst) {
			ans++;
			lst = e.second;
		}
	}

	out << ans << '\n';
	return 0;
}
