#include <iostream>
#include <vector>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)
#define repi(i, begin, end) for (int i = begin; i <= end; i += 1)
#define rep1(i, n) repi(i, 1, n)

using namespace std;
using lld = long long;
using llu = long long unsigned;
const llu MOD = 998244353;

void fileio() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
}

llu dfs(int now, int sum, int mx, int ec, const vector<int>& nums, const vector<int>& sumn) {
	int n = nums.size();
	
	if (now == n) {
		if (ec > 2 && sum > 2*mx) {
			return 1;
		}
		return 0;
	}
	
	llu res = 0;
	if (sum + (sumn[n]-sumn[now]) > 2 * max(mx, nums[now])) {
		res += dfs(now+1, sum+nums[now], max(mx, nums[now]), ec+1, nums, sumn);
	}
	res += dfs(now+1, sum, mx, ec, nums, sumn);
	
	if (n - now > 25) {
		res %= MOD;
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fileio();
	
	int n;
	cin >> n;
	
	vector<int> nums(n);
	rep(i, n) {
		cin >> nums[i];
	}
	
	vector<int> sumn(n+1);
	sumn[0] = 0;
	
	rep1(i, n) {
		sumn[i] = sumn[i-1] + nums[i-1];
	}
	
	cout << dfs(0, 0, 0, 0, nums, sumn) << endl;
	return 0;
}
