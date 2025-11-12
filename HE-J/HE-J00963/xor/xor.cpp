#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ls, rs;
	int len = 0;
	for (int l = 0, r = 0; l < n; l = r+1) {
		for (r = l; r < n; r++) {
			int s = 0;
			for (int i = l; i <= r; i++) {
				s ^= a[i];
			} 
			if (s == k) {
				ls.push_back(l);
				rs.push_back(r);
				len++;
				break;
			}
		}
	}	
	cout << len;
	return 0;
}
