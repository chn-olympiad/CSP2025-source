#include <iostream>
#include <vector>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)
#define repi(i, begin, end) for (int i = begin; i <= end; i += 1)
#define rep1(i, n) repi(i, 1, n)

using namespace std;
using iu = unsigned int;
const iu MAXK = (1 << 20) + 1;

void fileio() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fileio();
	
	int n;
	iu k;
	cin >> n >> k;
	
	vector<iu> nums(n);
	rep(i, n) {
		cin >> nums[i];
	}
	
	vector<iu> xorsum(n+1); // xorsum[i] = xor(nums_[0, i)) = nums[0] ^ ... ^ nums[i-1]
	xorsum[0] = 0;
	
	rep1(i, n) {
		xorsum[i] = xorsum[i-1] ^ nums[i-1];
	}
	
	auto get_xor = [&](int l, int r) {
		return xorsum[r] ^ xorsum[l];
	};
	
	vector<int> lastn(MAXK, -1); // 当前，xorsum[j]出现的最大j值 
	lastn[0] = 0;
	
	vector<int> f(n+1); // [0, i) 中最多几个区间 
	f[0] = 0;
	
	int last_add = 0;
	
	rep1(i, n) {
		f[i] = f[i-1];
		
		if (lastn[xorsum[i]^k] >= last_add) {
			f[i] += 1;
			last_add = i;
		}
		
		lastn[xorsum[i]] = i;
	}
	
	cout << f[n] << endl;
	return 0;
}
