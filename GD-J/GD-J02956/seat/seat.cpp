#include <iostream>
#include <vector>
#include <algorithm>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;

void fileio() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fileio();
	
	int n, m;
	cin >> n >> m;
	
	size_t len = n * m;
	vector<int> nums(len);
	
	rep(i, len) {
		cin >> nums[i];
	}
	
	int rv = nums[0];
	sort(nums.begin(), nums.end());
	
	int rp = lower_bound(nums.begin(), nums.end(), rv) - nums.begin();
	rp = len - rp - 1;
	
	int b = rp / n;
	int ta = rp % n;
	int a = ((b % 2 == 0) ? ta : (n - ta - 1));
	
	cout << b + 1 << " " << a + 1 << endl;
	return 0;
}
