#include <iostream>
#include <vector>
using namespace std;
#define N 500005

struct area {
	int l, r;
};
int n, k;
int a[N], sum[N];
vector<area> b;
int ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	for (int l=1; l<=n; ++l) {
		for (int r=l; r<=n; ++r) {
			if ((sum[r]^sum[l-1]) == k) {
				if (b.empty()) {
					b.push_back({l, r});
				}
				else {
					int bl = b.back().l, 
					br = b.back().r;
					if (l <= br) {
						if (r-l+1 < br-bl+1) {
							b.pop_back();
							b.push_back({l, r});
						}
					} else  {
						b.push_back({l, r});
					}
				}
			}
		}
	}
	cout << b.size() << endl;
	return 0;
}
